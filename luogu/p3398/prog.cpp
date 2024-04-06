#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<int>> tr;
vector<vector<int>> par;
vector<int> dep,fa;
void dfs(int u,int f){
    fa[u]=f,dep[u]=dep[f]+1;
    for(int v:tr[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}
void prep(){
    for(int i=1;i<=n;++i) par[i][0]=fa[i];
    for(int i=1;(1<<i)<=n;++i) for(int u=1;u<=n;++u) if(par[u][i-1]!=0) par[u][i]=par[par[u][i-1]][i-1];
}
int lca(int u,int v){
    if(dep[v]>dep[u]) swap(u,v);
    int dd=dep[u]-dep[v];
    for(int i=0;i<=30;++i) if((1<<i)&dd) u=par[u][i];
    if(u!=v){
        for(int i=30;i>=0;--i) if(par[u][i]!=0&&par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
        u=par[u][0];
    }
    return u;
}
int dis(int u,int v){
    int w=lca(u,v);
    return abs(dep[w]-dep[u])+abs(dep[w]-dep[v]);
}
int main(){
    cin>>n>>q;
    tr.resize(n+1);
    par.resize(n+1);
    dep.resize(n+1);
    fa.resize(n+1);
    for(int i=1;i<=n;++i) par[i].resize(40);
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dfs(1,0);
    prep();
    while(q--){
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d;
        e=lca(a,b),f=lca(c,d);
        if(dis(a,f)+dis(f,b)==dis(a,b)||dis(c,e)+dis(e,d)==dis(c,d)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}