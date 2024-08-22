// CF1985F - Final Boss
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int h,n,a[N],c[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
void solve(){
    ll ans=0;
    cin>>h>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>c[i];
    while(!pq.empty()) pq.pop();
    for(int i=1;i<=n;++i) pq.push({1,i});
    while(h>0){
        auto nw=pq.top();pq.pop();
        ans=nw.first;
        nw.first+=c[nw.second],h-=a[nw.second];
        pq.push(nw);
    }
    cout<<ans<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}