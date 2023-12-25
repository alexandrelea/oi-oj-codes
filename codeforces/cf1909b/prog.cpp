#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n;
long long a[N],ans;
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    ans=0;
    for(int i=1;i<n;++i) ans=__gcd(ans,abs(a[i+1]-a[i]));
    cout<<ans*2<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}