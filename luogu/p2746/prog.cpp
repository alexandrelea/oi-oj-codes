// 洛谷 p2746 - Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edges;
vector<int> gr[105];
void adde(int u,int v){
    // cerr<<u<<" "<<v<<endl;
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
int n,dfn[105],low[105],dft,scc[105],cscc;
int in[105],ou[105];
stack<int> stk;
void dfs(int u){
    dfn[u]=low[u]=++dft;
    stk.push(u);
    for(int ei:gr[u]){
        int v=edges[ei].v;
        if(dfn[v]==0) dfs(v),low[u]=min(low[u],low[v]);
        else if(scc[v]==0) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        ++cscc;
        while(!stk.empty()){
            int v=stk.top();stk.pop();
            scc[v]=cscc;
            if(v==u) break;
        }
    }
}
set<int> to[105];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int j;
        while(cin>>j&&j!=0) adde(i,j);
    }
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    for(auto e:edges){
        int u=e.u,v=e.v;
        if(scc[u]!=scc[v]) in[scc[v]]++,ou[scc[u]]++;
    }
    int ine=0,oue=0;
    for(int i=1;i<=cscc;++i) ine+=(in[i]==0),oue+=(ou[i]==0);
    cout<<ine<<endl<<(cscc!=1)*max(ine,oue)<<endl;
    return 0;
}