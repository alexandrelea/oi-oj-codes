// 洛谷 p8436 - 边双连通分量
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
int n,m,cco;
int dfn[N],low[N],dft,inv[N<<3],vis[N];
bool cnu[N<<3];
vector<edge> edges;
vector<int> gr[N],cop[N];
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
    edges.push_back(edge(v,u));
    gr[v].push_back(edges.size()-1);
    inv[edges.size()-1]=edges.size()-2;
    inv[edges.size()-2]=edges.size()-1;
}
void dfs(int u,int fa){
    dfn[u]=low[u]=++dft;
    for(int ei:gr[u]){
        int v=edges[ei].v;
        if(dfn[v]==0){
            dfs(v,u),low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) cnu[ei]=1,cnu[inv[ei]]=1;
        }else if(v!=fa&&dfn[v]!=0) low[u]=min(low[u],dfn[v]);
    }
}
void trav(int u){
    if(vis[u]!=0) return;
    vis[u]=cco;
    for(int ei:gr[u]){
        if(cnu[ei]) continue;
        int v=edges[ei].v;
        trav(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a,b);
    for(int i=1;i<=n;++i) if(dfn[i]==0) dfs(i,i);
    for(int i=1;i<=n;++i) if(vis[i]==0) ++cco,trav(i);
    for(int i=1;i<=n;++i) cop[vis[i]].push_back(i);
    cout<<cco<<endl;
    for(int i=1;i<=cco;++i){
        cout<<cop[i].size()<<" ";
        for(int je:cop[i]) cout<<je<<" ";
        cout<<endl;
    }
    return 0;
}