// QOJ #999 - 边双连通分量
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,dfn[N],low[N],dft,cnu[N<<1];
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
void dfs(int u,int fe){
    dfn[u]=low[u]=++dft;
    for(int ei:gr[u]){
        if(((ei|1)^1)==fe) continue;
        int v=edges[ei].v;
        if(dfn[v]==0){
            dfs(v,(ei|1)^1),low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) cnu[ei]=cnu[ei^1]=1;
        }else low[u]=min(low[u],dfn[v]);
    }
}
int vis[N],cvi;
void trac(int u){
    if(vis[u]!=0) return;
    vis[u]=cvi;
    for(int ei:gr[u]){
        if(cnu[ei]) continue;
        int v=edges[ei].v;
        trac(v);
    }
}
vector<int> ans[N];
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a+1,b+1),adde(b+1,a+1);
    for(int i=1;i<=n;++i) if(dfn[i]==0) dfs(i,-1);
    for(int i=1;i<=n;++i) if(vis[i]==0) ++cvi,trac(i);
    for(int i=1;i<=n;++i) ans[vis[i]].push_back(i);
    cout<<cvi<<endl;
    for(int i=1;i<=cvi;++i){
        cout<<ans[i].size()<<" ";
        for(int je:ans[i]) cout<<je-1<<" ";
        cout<<endl;
    }
    return 0;
}