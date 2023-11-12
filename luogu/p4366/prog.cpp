#include <bits/stdc++.h>
using namespace std;
const int N=1e5,NN=N+(1<<17);
int n,m,c,a,b,dis[NN],l;
bool vis[NN];
vector<pair<int,int>> G[NN];
set<pair<int,int>> s;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int main(){
    cin>>n>>m>>c,l=log2(n);
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        G[f].push_back({t,v});
        s.insert(make_pair(f,t));
    }
    cin>>a>>b;
    for(int u=1;u<=n+(1<<l);u++){
        for(int x=0;x<=l;x++){
            int v=u^(1<<x),w=u^v;
            G[u].push_back({v,w*c});
        }
        dis[u]=0x3f3f3f3f;
    }
    dis[a]=0,pq.push({dis[a],a});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto edge:G[u]){
            int v=edge.first,w=edge.second;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push({dis[v],v});
        }
    }
    cout<<dis[b]<<endl;
    return 0;
}