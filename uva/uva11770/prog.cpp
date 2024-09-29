// UVa 11770 - Lighting Away
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edgs;
vector<int> gr[N];
int n,dfn[N],low[N],scc[N],cscc,dft,m,in[N];
stack<int> stk;
void adde(int u,int v){
    edgs.push_back(edge(u,v));
    gr[u].push_back(edgs.size()-1);
}
void dfs(int u){
    dfn[u]=low[u]=++dft;
    stk.push(u);
    for(int e:gr[u]){
        int v=edgs[e].v;
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
void solve(int _){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        adde(a,b);
    }
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    for(auto e:edgs){
        int u=e.u,v=e.v;
        if(scc[u]!=scc[v]) ++in[scc[v]];
    }
    int ans=0;
    for(int i=1;i<=cscc;++i) if(in[i]==0) ++ans;
    cout<<"Case "<<_<<": "<<ans<<endl;

    edgs.clear();
    for(int i=1;i<=n;++i) gr[i].clear();
    memset(scc,0,sizeof(scc));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    cscc=dft=0;
    memset(in,0,sizeof(in));
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--) solve(++__);
    return 0;
}