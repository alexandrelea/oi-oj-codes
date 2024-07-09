#include <bits/stdc++.h>
#define int long long
const int N=1000,N2=N*N,inf=0x3f3f3f3f3f3f3f3f;
using namespace std;
int n,m,s[N+10],dis[N2+10],smax=0;
vector<pair<pair<int,int>,int>> eds;
vector<pair<int,int>> gr[N2+10];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool vis[N2+10];
void solve(){
    cin>>n>>m;
    eds.clear();
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        eds.push_back(make_pair(make_pair(u,v),w));
    }
    smax=0;
    for(int i=1;i<=n;++i) cin>>s[i],smax=max(smax,s[i]);
    for(int i=1;i<=n;++i) for(int j=1;j<=smax;++j) gr[i+n*(j-1)].clear(),dis[i+n*(j-1)]=inf,vis[i+n*(j-1)]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=smax;++j){
            if(j==s[i]) continue;
            gr[i+(j-1)*n].push_back(make_pair(i+(s[i]-1)*n,0));
        }
    }
    for(auto ie:eds){
        for(int j=1;j<=smax;++j){
            int u=n*(j-1)+ie.first.first,v=n*(j-1)+ie.first.second,w=j*ie.second;
            gr[u].push_back(make_pair(v,w)),gr[v].push_back(make_pair(u,w));
        }
    }
    dis[n*(s[1]-1)+1]=0,pq.push(make_pair(0,n*(s[1]-1)+1));
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto edge:gr[u]){
            int v=edge.first,w=edge.second;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push(make_pair(dis[v],v));
        }
    }
    int ans=inf;
    for(int i=1;i<=smax;++i) ans=min(ans,dis[i*n]);
    cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}