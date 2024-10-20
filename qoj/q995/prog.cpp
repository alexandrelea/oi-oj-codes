// QOJ #995 - 桥
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
int n,m;
vector<edge> edges;
vector<int> gr[N],ans;
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
int dfn[N],low[N],dft;
void dfs(int u,int fe){
    dfn[u]=low[u]=++dft;
    for(int ei:gr[u]){
        int v=edges[ei].v;
        if(((ei|1)^1)==fe) continue;
        if(dfn[v]==0){
            dfs(v,(ei|1)^1),low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) ans.push_back((ei|1)^1);
        }else low[u]=min(low[u],dfn[v]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a,b),adde(b,a);
    for(int i=1;i<=n;++i) if(dfn[i]==0) dfs(i,-1);
    sort(ans.begin(),ans.end());
    for(auto ie:ans) cout<<edges[ie].u<<" "<<edges[ie].v<<endl;
    return 0;
}