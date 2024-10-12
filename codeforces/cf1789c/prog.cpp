// Codeforces 1789C - Serval and Toxel's Arrays
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;
int n,m,a[N],vis[N],del[N];
void solve(){
    cin>>n>>m;
    int ans=0,sum=0;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n+m;++i) vis[i]=del[i]=0;
    for(int i=1;i<=m;++i){
        int p,v;
        cin>>p>>v;
        int tmp=i-vis[a[p]]+del[a[p]];
        sum+=tmp,del[a[p]]=tmp;
        sum-=del[v],vis[v]=i;
        ans+=n*i+sum,a[p]=v;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}