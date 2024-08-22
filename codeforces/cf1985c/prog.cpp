// CF1985C - Good Prefixes
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],aa[N];
void solve(){
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],aa[i]=a[i]+aa[i-1];
    set<int> S;
    for(int i=1;i<=n;++i){
        S.insert(2*a[i]);
        if(S.count(aa[i])) ++ans;
    }
    cout<<ans<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}