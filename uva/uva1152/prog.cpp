#include <bits/stdc++.h>
// #define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    int t,n,a[4010]={},b[4010]={},c[4010]={},d[4010]={},_=0;
    cin>>t;
    while(t--){
        if(_) cout<<endl;
        unordered_map<int,int> cd;
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i]>>d[i];
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cd[c[i]+d[j]]++;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ans+=cd[-a[i]-b[j]];
        cout<<ans<<endl;
        _=1;
    }
    return 0;
}