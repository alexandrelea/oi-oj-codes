#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define int long long
using namespace std;
const int SIZE=2510;
int n,m,k,scor[SIZE],dis[SIZE],ans=0;
bool vis[SIZE],conn[SIZE][SIZE];
vector<int> edge[SIZE];
vector<pair<int,int>> anss[SIZE];
priority_queue<pair<int,int>> wr[SIZE];
signed main(){
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++) cin>>scor[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[i]=0,pq.push(make_pair(0,i));
        while(!pq.empty()){
            int u=pq.top().second;pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for(auto v:edge[u]){
                if(dis[v]>dis[u]+1&&dis[u]+1<=k+1){
                    dis[v]=dis[u]+1;
                    conn[u][v]=conn[v][u]=true;
                    conn[i][v]=conn[v][i]=true;
                    pq.push(make_pair(dis[v],v));
                }
            }
        }
    }
    for(int v=1;v<=n;v++){
        for(int u=1;u<=n;u++){
            if(conn[1][u]&&conn[u][v]&&u!=v&&v!=1&&u!=1){
                wr[v].push(make_pair(scor[u]+scor[v],u));
            }
        }
    }
    for(int u=1;u<=n;u++) for(int k=3;k;k--) if(!wr[u].empty()) anss[u].push_back(wr[u].top()),wr[u].pop();
    for(int v=2;v<=n;v++) for(int w=2;w<=n;w++){
        if(v!=w&&conn[v][w]&&(!anss[v].empty())&&(!anss[w].empty())){
            for(auto lk0:anss[v]) for(auto lk1:anss[w]){
                if(lk0.second!=lk1.second&&lk0.second!=w&&lk1.second!=v) ans=max(ans,lk0.first+lk1.first);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}