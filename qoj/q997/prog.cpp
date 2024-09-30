// QOJ 997 - 2-SAT 问题
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
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
int dfn[2*N],low[2*N],scc[2*N],cscc,dft;
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
        cscc++;
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
        int a,b;
        bool va,vb,na,nb;
        cin>>a>>va>>b>>vb;
        na=!va,nb=!vb;
        adde(a+na*n,b+vb*n); // !a or b
        adde(b+nb*n,a+va*n); // !b or a
    }
    for(int i=1;i<=n*2;++i) if(scc[i]==0) dfs(i);
    bool ok=1;
    for(int i=1;i<=n;++i) if(scc[i]==scc[i+n]) ok=0;
    if(ok){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;++i) cout<<(scc[i]>scc[i+n])<<" ";
    }else cout<<"No"<<endl;
    return 0;
}