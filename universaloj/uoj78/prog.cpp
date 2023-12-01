#include <bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,e,ans,mah[N],ani[N];
vector<int> edge[N];
bool vis[N];
bool dfs(int u){
    for(auto v:edge[u]){
        if(vis[v]) continue;
        vis[v]=true;
        if(mah[v]==0||dfs(mah[v])) return mah[v]=u;
    }
    return false;
}
int main(){
    cin>>n>>m>>e;
    for(int i=1;i<=e;++i){
        int v,u;
        cin>>v>>u;
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ++ans;
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;++i) ani[mah[i]]=i;
    for(int i=1;i<=n;++i) cout<<ani[i]<<" ";
    return 0;
}