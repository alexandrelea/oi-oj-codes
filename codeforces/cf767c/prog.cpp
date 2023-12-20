#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,t[N],r,sum[N],sm=0;
vector<int> tr[N];
int ans[N],cnt;
void dfs(int u){
    sum[u]=t[u];
    for(int v:tr[u]) dfs(v),sum[u]+=sum[v];
    if(sum[u]*3==sm&&u!=r) ans[++cnt]=u,sum[u]=0;
    if(cnt==2) cout<<ans[1]<<" "<<ans[2]<<endl,exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x>>t[i];
        if(x==0) r=i;
        else tr[x].push_back(i);
        sm+=t[i];
    }
    if(sm%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    dfs(r);
    cout<<-1<<endl;
    return 0;
}