// 洛谷 p4171 - 满汉全席
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edges;
vector<int> gr[N];
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
int dfn[N],low[N],scc[N],cscc,dft;
stack<int> stk;
void dfs(int u){
    dfn[u]=low[u]=++dft;
    stk.push(u);
    for(int e:gr[u]){
        int v=edges[e].v;
        if(dfn[v]==0) dfs(v),low[u]=min(low[u],low[v]);
        else if(scc[v]==0) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        ++cscc;
        while(1){
            int v=stk.top();stk.pop();
            scc[v]=cscc;
            if(u==v) break;
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b,va,vb,na,nb;
        char ca,cb;
        cin>>ca>>a>>cb>>b;
        va=(ca=='m'),na=!va;
        vb=(cb=='m'),nb=!vb;
        adde(a+na*n,b+vb*n);
        adde(b+nb*n,a+va*n);
    }
    for(int i=1;i<=n*2;++i) if(scc[i]==0) dfs(i);
    bool ok=1;
    for(int i=1;i<=n;++i) if(scc[i]==scc[i+n]){
        ok=0;
        break;
    }
    if(ok) cout<<"GOOD"<<endl;
    else cout<<"BAD"<<endl;

    edges.clear();
    for(int i=1;i<=n*2;++i) gr[i].clear(),dfn[i]=low[i]=scc[i]=0;
    cscc=dft=0;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}