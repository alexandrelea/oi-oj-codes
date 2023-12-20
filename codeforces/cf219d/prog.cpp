#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;
int n,dp[N],ans=INF;
vector<pair<int,bool>> tr[N];
void dfs(int u,int fa){
    for(auto edge:tr[u]){
        int v=edge.first,w=edge.second;
        if(v==fa) continue;
        if(w==1) dp[1]++;
        dfs(v,u);
    }
}
void dfs2(int u,int fa){
    for(auto edge:tr[u]){
        int v=edge.first,w=edge.second;
        if(v==fa) continue;
        if(w==1) dp[v]=dp[u]-1;
        else dp[v]=dp[u]+1;
        dfs2(v,u);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        tr[u].push_back({v,0});
        tr[v].push_back({u,1});
    }
    dfs(1,1),dfs2(1,1);
    for(int i=1;i<=n;++i) ans=min(ans,dp[i]);
    cout<<ans<<endl;
    for(int i=1;i<=n;++i) if(dp[i]==ans){
        cout<<i<<" ";
    }
    return 0;
}