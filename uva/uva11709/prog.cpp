// UVa 11709 - Trust groups
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> n2i;
struct edge{
    int u,v;
};
vector<edge> edgs;
vector<int> gr[1005];
void adde(int u,int v){
    edgs.push_back(edge{u,v});
    gr[u].push_back(edgs.size()-1);
}
int dfn[1005],scc[1005],low[1005],cscc,dft;
stack<int> stk;
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
            int v=stk.top();
            stk.pop();
            scc[v]=cscc;
            if(u==v) break;
        }
    }
}
void solve(){
    cin.get();
    for(int i=1;i<=n;++i){
        string nam;
        getline(cin,nam);
        n2i[nam]=i;
        // cerr<<nam<<" "<<i<<endl;
    }
    for(int i=1;i<=m;++i){
        string n1,n2;
        getline(cin,n1),getline(cin,n2);
        adde(n2i[n1],n2i[n2]);
        // cerr<<n2i[n1]<<" "<<n2i[n2]<<endl;
    }
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    cout<<cscc<<endl;
    cscc=dft=0,n2i.clear(),edgs.clear();
    for(int i=1;i<=n;++i) gr[i].clear(),dfn[i]=scc[i]=low[i]=0;
}
int main(){
    while(cin>>n>>m&&(n||m)) solve();
    return 0;
}