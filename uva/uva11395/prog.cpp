#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
void solve(){
    int ans=0;
    for(int i=1;i<=sqrt(n);i++){
        ++ans;
        int t=i*i*2ll;
        if(t<=n) ++ans;
    }
    cout<<n-ans<<endl;
}
signed main(){
    while(cin>>n&&n!=0) solve();
    return 0;
}