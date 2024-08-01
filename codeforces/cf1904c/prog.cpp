#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e6+5,inf=0x3f3f3f3f;
int n,k,a[N];
int solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(k>=3) return 0;
    sort(a+1,a+n+1);
    int ans=a[1];
    for(int i=1;i<n;++i) ans=min(ans,a[i+1]-a[i]);
    if(k==1) return ans;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
        int v=abs(a[i]-a[j]),p=lower_bound(a+1,a+n+1,v)-a;
        if(p<=n) ans=min(ans,abs(a[p]-v));
        if(p>1) ans=min(ans,abs(a[p-1]-v));
    }
    return ans;
}
signed main(){
    int _;
    cin>>_;
    while(_--) cout<<solve()<<endl;
    return 0;
}