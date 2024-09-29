// UVa 11838 - Come and Go
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edgs;
vector<int> gr[N];
stack<int> stk;
void adde(int u,int v){
    edgs.push_back(edge(u,v));
    gr[u].push_back(edgs.size()-1);
}
int n,m,dfn[N],low[N],scc[N],dft,cscc;
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
        while(1){
            int v=stk.top();stk.pop();
            scc[v]=cscc;
            if(v==u) break;
        }
    }
}
void solve(){
    for(int i=1,a,b,p;i<=m;++i){
        cin>>a>>b>>p;
        adde(a,b);
        if(p==2) adde(b,a);
    }
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    if(cscc==1) cout<<1<<endl;
    else cout<<0<<endl;
    edgs.clear();
    for(int i=1;i<=n;++i) gr[i].clear(),dfn[i]=low[i]=scc[i]=0;
    dft=cscc=0;
}
int main(){
    while(cin>>n>>m&&(n||m)) solve();
    return 0;
}