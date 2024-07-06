#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long sumw,ans,f[N+10][2];
vector<pair<int,long long>> tr[N+10];
void dp(int u,int fa){
    f[u][0]=f[u][1]=0;
    for(auto eg:tr[u]){
        int v=eg.first;
        long long w=eg.second;
        if(v==fa) continue;
        dp(v,u);
        long long tm=f[v][0]+w;
        if(tm>=f[u][0]) f[u][1]=f[u][0],f[u][0]=tm;
        else if(tm>=f[u][1]) f[u][1]=tm;
    }
    ans=max(ans,f[u][0]+f[u][1]);
}
int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        tr[u].push_back({v,w});
        tr[v].push_back({u,w});
        sumw+=2*w;
    }
    dp(1,0);
    cerr<<sumw<<" "<<ans<<endl;
    cout<<sumw-ans<<endl;
    return 0;
}