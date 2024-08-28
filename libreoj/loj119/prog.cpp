// LibreOJ #119 - 单源最短路
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2505;
int n,m,s,t,dis[N];
bool vis[N];
struct edg{
    int u,v,w;
    edg(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edg> edge;
vector<int> gr[N];
void nwedg(int u,int v,int w){
    edge.push_back(edg(u,v,w));
    gr[u].push_back(edge.end()-edge.begin()-1);
    edge.push_back(edg(v,u,w));
    gr[v].push_back(edge.end()-edge.begin()-1);
}
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0,pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int ie:gr[u]){
            int v=edge[ie].v,w=edge[ie].w;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push({dis[v],v});
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        nwedg(u,v,w);
    }
    dijkstra(s);
    cout<<dis[t]<<endl;
    return 0;
}