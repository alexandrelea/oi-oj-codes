#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF=1e9,SIZE=1e6+10;
typedef long long lnt;
bool spfa(int n,int s,vector<vector<pair<int,lnt>>> edge,lnt dis[]){
    queue<int> que;
    bool vis[SIZE];
    int vied[SIZE];
    for(int i=1;i<=n;i++) dis[i]=(i==s?0:INF),vis[i]=false,vied[i]=0;
    que.push(s);
    while(!que.empty()){
        int u=que.front();que.pop();
        vis[u]=false;
        for(auto edg:edge[u]){
            int v=edg.first;
            lnt w=edg.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    que.push(v);vis[v]=true;
                    vied[v]++;
                    if(vied[v]==n+1) return false;
                }
            }
        }
    }
    return true;
}
void dijkstra(int n,int s,vector<vector<pair<int,lnt>>> edge,lnt dis[]){
    priority_queue<pair<int,lnt>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    bool vis[SIZE];
    for(int i=1;i<=n;i++) dis[i]=(i==s?0:INF),vis[i]=false;
    pq.push(make_pair(dis[s],s));
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto edg:edge[u]){
            int v=edg.first;
            lnt w=edg.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
int main(){
    lnt n,m,dis[SIZE],dih[SIZE];
    vector<vector<pair<int,lnt>>> edge;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++) edge.push_back(vector<pair<int,lnt>>());
    for(int i=1;i<=m;i++){
        int u,v;
        lnt w;
        cin>>u>>v>>w;
        edge[u].push_back(make_pair(v,w));
    }
    for(int i=1;i<=n;i++) edge[n+1].push_back(make_pair(i,0));
    if(!spfa(n+1,n+1,edge,dih)) return cout<<-1<<endl,0;
    for(int u=1;u<=n;u++){
        for(auto &edg:edge[u]){
            int v=edg.first,w=edg.second;
            edg.second=w-dih[v]+dih[u];
        }
    }
    for(int u=1;u<=n;u++){
        dijkstra(n,u,edge,dis);
        lnt ans=0;
        for(int v=1;v<=n;v++) ans+=(dis[v]!=INF?(dis[v]-dih[u]+dih[v]):INF)*v;
        cout<<ans<<endl;
    }
    return 0;
}
