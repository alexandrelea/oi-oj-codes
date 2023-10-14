#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int SIZE=1e5+10;
int n,q;
int dep[SIZE],fa[SIZE],siz[SIZE];
int wson[SIZE],toch[SIZE],dfn[SIZE],ren[SIZE],dft;
vector<int> edge[SIZE];
struct nodt{
    int lf,rt;
    mutable int val;
    nodt(int l,int r,int v):lf(l),rt(r),val(v){}
    bool operator<(const nodt x)const{
        return lf<x.lf;
    }
};
set<nodt> odt;
auto split(int x){
    auto it=--odt.upper_bound(nodt(x,0,0));
    if(it->lf==x) return it;
    int l=it->lf,r=it->rt,v=it->val;
    odt.erase(it);
    odt.insert(nodt(l,x-1,v));
    return odt.insert(nodt(x,r,v)).first;
}
int assign(int l,int r,int v){
    auto rit=split(r+1),lit=split(l);
    int all=v*(r-l+1),sum=0;
    for(auto it=lit;it!=rit;it++) sum+=it->val*(it->rt-it->lf+1);
    odt.erase(lit,rit),odt.insert(nodt(l,r,v));
    return abs(all-sum);
}
void dfs(int u,int fah,int dept){
    dep[u]=dept,fa[u]=fah,siz[u]=1;
    for(auto v:edge[u]){
        if(v==fah) continue;
        dfs(v,u,dept+1);
        siz[u]+=siz[v];
        if(siz[wson[u]]<siz[v]) wson[u]=v;
    }
}
void subd(int u,int top){
    toch[u]=top,dfn[u]=++dft,ren[dft]=u;
    //cout<<u<<endl;
    if(wson[u]==0) return;
    subd(wson[u],top);
    for(auto v:edge[u]){
        if(v==fa[u]||v==wson[u]) continue;
        subd(v,v);
    }
}
int install(int x,int y){
    int ans=0;
    while(toch[x]!=toch[y]){
        if(dep[toch[x]]<dep[toch[y]]) swap(x,y);
        ans+=assign(dfn[toch[x]],dfn[x],1);
        x=fa[toch[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    ans+=assign(dfn[x],dfn[y],1);
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        edge[i+1].push_back(x+1),edge[x+1].push_back(i+1);
    }
    dfs(1,0,1);
    subd(1,1);
    odt.insert(nodt(1,n+1,0));
    cin>>q;
    while(q--){
        string op;
        int x;
        cin>>op>>x;
        if(op=="uninstall") cout<<assign(dfn[x+1],dfn[x+1]+siz[x+1]-1,0)<<endl;
        else cout<<install(x+1,1)<<endl;
    }
    return 0;
}
// 1<<(1<<n)