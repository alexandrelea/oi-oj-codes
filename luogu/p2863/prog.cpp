// 洛谷 p2863 - [USACO06JAN] The Cow Prom S
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
int n,m,dfn[N],low[N],dft,scc[N],cscc,tot[N];
stack<int> stk;
vector<edge> edges;
vector<int> gr[N];
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
void dfs(int u){
    dfn[u]=low[u]=++dft;
    stk.push(u);
    for(int ie:gr[u]){
        int v=edges[ie].v;
        if(dfn[v]==0) dfs(v),low[u]=min(low[u],low[v]);
        else if(scc[v]==0) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++cscc;
        while(!stk.empty()){
            int v=stk.top();stk.pop();
            scc[v]=cscc;
            if(v==u) break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a,b);
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    for(int i=1;i<=n;++i) tot[scc[i]]++,cerr<<(low[i]==dfn[i]);
    int ans=0;
    for(int i=1;i<=cscc;++i) if(tot[i]>1) ++ans;
    cout<<ans<<endl;
    return 0;
}