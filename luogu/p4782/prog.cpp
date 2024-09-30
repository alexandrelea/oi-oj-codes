// 洛谷 p4782 - 2-SAT
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edges;
vector<int> gr[2*N];
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
int n,m,dfn[2*N],low[2*N],scc[2*N],cscc,dft;
stack<int> stk;
void dfs(int u){
    dfn[u]=low[u]=++dft;
    stk.push(u);
    for(int e:gr[u]){
        int v=edges[e].v;
        if(dfn[v]==0) dfs(v),low[u]=min(low[u],low[v]);
        else if(scc[v]==0) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++cscc;
        while(1){
            int v=stk.top();stk.pop();
            scc[v]=cscc;
            if(v==u) break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v,uu,vv,uuu,vvv;
        cin>>u>>uu>>v>>vv,uuu=!uu,vvv=!vv;
        adde(u+uuu*n,v+vv*n);
        adde(v+vvv*n,u+uu*n);
    }
    bool ok=1;
    for(int i=1;i<=n*2;++i) if(scc[i]==0) dfs(i);
    for(int i=1;i<=n;++i) if(scc[i]==scc[i+n]) ok=0;
    if(ok){
        cout<<"POSSIBLE"<<endl;
        for(int i=1;i<=n;++i) cout<<(scc[i]>scc[i+n])<<" ";
        cout<<endl;
    }else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}