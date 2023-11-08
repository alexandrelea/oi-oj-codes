#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+10;
int n,m;
vector<int> G[SIZE];
int siz[SIZE],fh[SIZE],dep[SIZE];
int wson[SIZE],toch[SIZE],dfn[SIZE],dft;
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
struct noodt{
    int l,r;
    mutable int val;
    noodt(int l,int r=-1,int val=0):l(l),r(r),val(val){}
    bool operator<(const noodt &rhs)const{
        return l<rhs.l;
    }
};
set<noodt> odt;
typedef set<noodt>::iterator iter;
iter split(int pos){
    iter it=odt.lower_bound(noodt(pos));
    if(it!=odt.end()&&it->l==pos) return it;
    --it;
    int l=it->l,r=it->r,val=it->val;
    odt.erase(it);
    odt.insert(noodt(l,pos-1,val));
    return odt.insert(noodt(pos,r,val)).first;
}
void assign(int lf,int rt,int val){
    iter itr=split(rt+1),itl=split(lf);
    odt.erase(itl,itr);
    odt.insert(noodt(lf,rt,val));
}
int query(int pos){
    iter itat=split(pos);
    return itat->val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    subd(1,1);
    odt.insert(noodt(0,n+1,0));
    cin>>m;
    while(m--){
        int o,u;
        cin>>o>>u;
        if(o==1) assign(dfn[u],dfn[u]+siz[u]-1,1);
        if(o==2){
            while(toch[u]!=1) assign(dfn[toch[u]],dfn[u],0),u=fh[toch[u]];
            assign(dfn[1],dfn[u],0);
        }
        if(o==3) cout<<query(dfn[u])<<endl;
    }
    return 0;
}