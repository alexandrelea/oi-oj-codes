#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],sa[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) sa[i]=sa[i-1]+a[i];
    int L=1,R=0,ans=0;
    for(int i=1;i<=n;++i){
        ++R;
        while((a[R]-a[L]>1||sa[R]-sa[L-1]>m)&&L<=n) ++L;
        ans=max(ans,sa[R]-sa[L-1]);
    }
    cout<<ans<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}