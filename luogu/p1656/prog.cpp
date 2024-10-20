// 洛谷 p1656 - 炸铁路
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=305;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> edges,ans;
vector<int> gr[N];
void adde(int u,int v){
    edges.push_back(edge(u,v));
    gr[u].push_back(edges.size()-1);
}
int n,m,dfn[N],low[N],dft;
void dfs(int u,int fa){
    dfn[u]=low[u]=++dft;
    for(int ei:gr[u]){
        int v=edges[ei].v;
        if(dfn[v]==0){
            dfs(v,u),low[u]=min(low[v],low[u]);
            if(dfn[u]<low[v]) ans.push_back(edge(min(u,v),max(u,v)));
        }else if(v!=fa&&dfn[v]!=0) low[u]=min(low[u],dfn[v]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1,a,b;i<=m;++i) cin>>a>>b,adde(a,b),adde(b,a);
    for(int i=1;i<=n;++i) if(dfn[i]==0) dfs(i,0);
    sort(ans.begin(),ans.end(),[](edge a,edge b)->bool {return a.u!=b.u?a.u<b.u:a.v<b.v;});
    for(edge e:ans) cout<<e.u<<" "<<e.v<<endl;
    return 0;
}