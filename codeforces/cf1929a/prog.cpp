#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,a[N];
void solve(){
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i) ans+=a[i]-a[i-1];
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}