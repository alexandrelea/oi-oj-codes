#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,a[N];
void solve(){
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=k;++i) cin>>a[i];
    sort(a+1,a+k+1);
    for(int i=1;i<k;++i) if(a[i]==1) ans+=a[i]; else ans+=a[i]*2-1;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}