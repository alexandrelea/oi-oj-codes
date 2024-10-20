// QOJ #996 - 割点
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
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
int dfn[N],low[N],ic[N],dft;
void dfs(int u,int fa){
    int ch=0;
    dfn[u]=low[u]=++dft;
    for(int e:gr[u]){
        int v=edges[e].v;
        if(dfn[v]==0) dfs(v,u),low[u]=min(low[u],low[v]),++ch,ic[u]|=(low[v]>=dfn[u]);
        else if(dfn[v]<dfn[u]&&v!=fa) low[u]=min(low[u],low[v]);
    }
    if(fa==0&&ch==1) ic[u]=0;
}
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a,b),adde(b,a);
    for(int i=1;i<=n;++i) if(dfn[i]==0) dfs(i,0);
    int ans=0;
    for(int i=1;i<=n;++i) if(ic[i]) ++ans;
    cout<<ans<<endl;
    for(int i=1;i<=n;++i) if(ic[i]) cout<<i<<" ";
    cout<<endl;
    return 0;
}