// 洛谷 p3387 - 【模板】缩点
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1'0000;
struct edg{
    int u,v;
    edg(int u=0,int v=0):u(u),v(v){}
};
int n,m,w[N],dfn[N],low[N],dft,scc[N],cscc,wei[N],in[N],dis[N];
vector<edg> edgs,edgss;
vector<int> gr[N],grr[N];
void nwedg(int u,int v){
    edgs.push_back(edg(u,v));
    gr[u].push_back(edgs.size()-1);
}
void nwedgg(int u,int v){
    edgss.push_back(edg(u,v));
    grr[u].push_back(edgss.size()-1);
}
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
            scc[v]=cscc,stk.pop();
            if(v==u) break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>w[i];
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        nwedg(u,v);
    }
    for(int i=1;i<=n;++i) if(scc[i]==0) dfs(i);
    queue<int> que;
    for(auto e:edgs){
        int u=e.u,v=e.v;
        u=scc[u],v=scc[v];
        if(u!=v) nwedgg(u,v),in[v]++;
    }
    int ans=0;
    for(int i=1;i<=n;++i) wei[scc[i]]+=w[i],dis[scc[i]]=wei[scc[i]];
    for(int i=1;i<=cscc;++i) if(in[i]==0) que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        for(int e:grr[u]){
            int v=edgss[e].v;
            dis[v]=max(dis[v],wei[v]+dis[u]);
            --in[v];
            if(in[v]==0) que.push(v);
        }
    }
    for(int i=1;i<=n;++i) ans=max(ans,dis[i]);
    cout<<ans<<endl;
    return 0;
}