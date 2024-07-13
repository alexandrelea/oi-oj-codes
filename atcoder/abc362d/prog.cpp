#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],dis[N],m;
vector<pair<int,int>> gr[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool vis[N];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        gr[u].push_back(make_pair(v,w));
        gr[v].push_back(make_pair(u,w));
    }
    memset(dis,0x3f,sizeof dis);
    
    dis[1]=a[1],pq.push(make_pair(a[1],1));
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto edg:gr[u]){
            int v=edg.first,w=edg.second+a[v];
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push(make_pair(dis[v],v));
        }
    }
    for(int i=2;i<=n;++i) cout<<dis[i]<<" ";
    return 0;
}