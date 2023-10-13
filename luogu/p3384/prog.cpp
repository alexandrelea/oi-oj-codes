#include <iostream>
#include <vector>
using namespace std;
const int SIZE=1e5+10;
int n,m,r,p;
int fa[SIZE],dep[SIZE],a[SIZE],siz[SIZE];
int wson[SIZE],toch[SIZE],dfn[SIZE],opd[SIZE],dft=0;
int sum[SIZE*4],lzyt[SIZE*4];
vector<int> edge[SIZE];
void dfs(int u,int fat,int dept){
    fa[u]=fat,dep[u]=dept,siz[u]=1;
    for(auto v:edge[u]){
        if(v==fat) continue;
        dfs(v,u,dept+1);
        siz[u]+=siz[v];
        if(siz[v]>siz[wson[u]]) wson[u]=v;
    }
}
void subd(int u,int t){
    toch[u]=t,dfn[u]=++dft,opd[dft]=u;
    if(wson[u]==0) return;
    subd(wson[u],t);
    for(auto v:edge[u]){
        if(v==wson[u]||v==fa[u]) continue;
        subd(v,v);
    }
}
void pushdown(int co,int lf,int rt){
    if(lzyt[co]==0) return;
    int mid=lf+(rt-lf)/2;
    lzyt[co*2]+=lzyt[co],sum[co*2]+=lzyt[co]*(mid-lf+1),lzyt[co*2]%=p,sum[co*2]%=p;
    lzyt[co*2+1]+=lzyt[co],sum[co*2+1]+=lzyt[co]*(rt-mid),lzyt[co*2+1]%=p,sum[co*2+1]%=p;
    lzyt[co]=0;
}
void build(int co,int lf,int rt){
    lzyt[co]=0;
    if(lf==rt) return sum[co]=a[opd[lf]]%p,void();
    int mid=lf+(rt-lf)/2;
    build(co*2,lf,mid),build(co*2+1,mid+1,rt);
    sum[co]=(sum[co*2]+sum[co*2+1])%p;
}
int query(int co,int lf,int rt,int ql,int qr){
    if(ql<=lf&&rt<=qr) return sum[co]%p;
    int ans=0,mid=lf+(rt-lf)/2;
    pushdown(co,lf,rt);
    if(ql<=mid) ans+=query(co*2,lf,mid,ql,qr),ans%=p;
    if(mid<qr) ans+=query(co*2+1,mid+1,rt,ql,qr),ans%=p;
    return ans%p;
}
void modify(int co,int lf,int rt,int ml,int mr,int mv){
    if(ml<=lf&&rt<=mr) return sum[co]+=mv*(rt-lf+1),lzyt[co]+=mv,sum[co]%=p,lzyt[co]%=p,void();
    pushdown(co,lf,rt);
    int mid=lf+(rt-lf)/2;
    if(ml<=mid) modify(co*2,lf,mid,ml,mr,mv);
    if(mid<mr) modify(co*2+1,mid+1,rt,ml,mr,mv);
    sum[co]=(sum[co*2]+sum[co*2+1])%p;
}
int inquire(int x,int y){
    int ans=0,tx=toch[x],ty=toch[y];
    while(tx!=ty){
        if(dep[tx]>=dep[ty]) ans=ans+query(1,1,n,dfn[tx],dfn[x]),ans%=p,x=fa[tx],tx=toch[x];
        else ans=ans+query(1,1,n,dfn[ty],dfn[y]),ans%=p,y=fa[ty],ty=toch[y];
    }
    if(dfn[x]<=dfn[y]) ans=ans+query(1,1,n,dfn[x],dfn[y]),ans=ans%p;
    else ans=ans+query(1,1,n,dfn[y],dfn[x]),ans=ans%p;
    return ans%p;
}
void update(int x,int y,int c){
    int tx=toch[x],ty=toch[y];
    while(tx!=ty){
        if(dep[tx]>=dep[ty]) modify(1,1,n,dfn[tx],dfn[x],c),x=fa[tx],tx=toch[x];
        else modify(1,1,n,dfn[ty],dfn[y],c),y=fa[ty],ty=toch[y];
    }
    if(dfn[x]<=dfn[y]) modify(1,1,n,dfn[x],dfn[y],c);
    else modify(1,1,n,dfn[y],dfn[x],c);
}
int main(){
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y),edge[y].push_back(x);
    }
    dft=0,dfs(r,0,1),subd(r,r),build(1,1,n);
    while(m--){
        int o,x,y,z;
        cin>>o>>x;
        if(o==1) cin>>y>>z,update(x,y,z%p);
        if(o==2) cin>>y,cout<<inquire(x,y)<<endl;
        if(o==3) cin>>z,modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,z%p);
        if(o==4) cout<<query(1,1,n,dfn[x],dfn[x]+siz[x]-1)<<endl;
    }
    return 0;
}