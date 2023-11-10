#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e5+10;
int n,t[SIZE],m;
vector<int> G[SIZE];
int siz[SIZE],fh[SIZE],dep[SIZE];
int wson[SIZE],toch[SIZE],dfn[SIZE],dft=0;
int cnt1[SIZE*4],ln[SIZE*4],tag[SIZE*4];
void dfs(int u,int fa){
    siz[u]=1,fh[u]=fa,dep[u]=dep[fa]+1;
    for(int v:G[u]){
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[wson[u]]<siz[v]) wson[u]=v;
    }
}
void subd(int u,int top){
    toch[u]=top,dfn[u]=++dft;
    if(wson[u]==0) return;
    subd(wson[u],top);
    for(int v:G[u]){
        if(v==fh[u]||v==wson[u]) continue;
        subd(v,v);
    }
}
void build(int co,int lf,int rt){
    // cout<<"bu "<<co<<" "<<lf<<" "<<rt<<endl;
    ln[co]=rt-lf+1;
    if(lf==rt){
        cnt1[co]=t[lf];
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(co*2,lf,mi);
    build(co*2+1,mi+1,rt);
    cnt1[co]=cnt1[co*2]+cnt1[co*2+1];
}
void pushdown(int co){
    if(tag[co]==0) return;
    cnt1[co*2]=ln[co*2]-cnt1[co*2];
    cnt1[co*2+1]=ln[co*2+1]-cnt1[co*2+1];
    tag[co*2]=!tag[co*2];
    tag[co*2+1]=!tag[co*2+1];
    tag[co]=0;
}
void modify(int co,int lf,int rt,int mlf,int mrt){
    // cout<<"mf "<<co<<" "<<lf<<" "<<rt<<" "<<mlf<<" "<<mrt<<endl;
    if(mlf<=lf&&rt<=mrt){
        tag[co]=!tag[co];
        cnt1[co]=ln[co]-cnt1[co];
        return;
    }
    pushdown(co);
    int mi=lf+(rt-lf)/2;
    if(mlf<=mi) modify(co*2,lf,mi,mlf,mrt);
    if(mi<mrt) modify(co*2+1,mi+1,rt,mlf,mrt);
    cnt1[co]=cnt1[co*2]+cnt1[co*2+1];
}
int query(int co,int lf,int rt,int qlf,int qrt){
    // cout<<"qu "<<co<<" "<<lf<<" "<<rt<<" "<<qlf<<" "<<qrt<<endl;
    if(qlf<=lf&&rt<=qrt) return cnt1[co];
    pushdown(co);
    int mi=lf+(rt-lf)/2,qans=0;
    if(qlf<=mi) qans+=query(co*2,lf,mi,qlf,qrt);
    if(mi<qrt) qans+=query(co*2+1,mi+1,rt,qlf,qrt);
    return qans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        G[x].push_back(i),G[i].push_back(x);
    }
    dfs(1,1),subd(1,1);
    for(int i=1;i<=n;i++) cin>>t[dfn[i]];
    build(1,1,n);
    cin>>m;
    while(m--){
        string op;
        int u;
        cin>>op>>u;
        if(op=="pow") modify(1,1,n,dfn[u],dfn[u]+siz[u]-1);
        if(op=="get") cout<<query(1,1,n,dfn[u],dfn[u]+siz[u]-1)<<endl;
    }
    return 0;
}