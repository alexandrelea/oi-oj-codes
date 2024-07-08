#include <bits/stdc++.h>
using namespace std;
int n,k,t[110],dis[610],vis[610];
vector<pair<int,int>> gr[610];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void solve(){
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;++i){
        cin>>t[i];
        for(int j=0;j<=99;++j) gr[i*100+j].clear();
    }
    for(int i=0;i<=99;++i) for(int j=1;j<=n;++j) for(int k=j+1;k<=n;++k){
        int u=100*j+i,v=100*k+i;
        gr[u].push_back(make_pair(v,60));
        gr[v].push_back(make_pair(u,60));
    }
    cin.get();
    for(int i=1;i<=n;++i){
        string ss;
        getline(cin,ss);
        stringstream sin(ss);
        int f0,f1;
        sin>>f0;
        while(sin>>f1){
            int u=100*i+f0,v=100*i+f1,w=t[i]*(f1-f0);
            gr[u].push_back(make_pair(v,w));
            gr[v].push_back(make_pair(u,w));
            f0=f1;
        }
    }
    // for(int i=0;i<=99;++i) for(int j=1;j<=n;++j) for(auto ke:gr[j*100+i]) cerr<<j*100+i<<" "<<ke.second<<" "<<ke.first<<endl;
    for(int i=1;i<=99;++i) for(int j=1;j<=n;++j) dis[100*j+i]=0x3f3f3f3f,vis[100*j+i]=false;
    for(int j=1;j<=n;++j) pq.push(make_pair(0,100*j)),vis[100*j]=false;
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto edg:gr[u]){
            int v=edg.first,w=edg.second;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push(make_pair(dis[v],v));
        }
    }
    for(int i=1;i<=n;++i) ans=min(ans,dis[100*i+k]);
    if(ans==0x3f3f3f3f) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}
int main(){
    while(cin>>n>>k) solve();
    return 0;
}