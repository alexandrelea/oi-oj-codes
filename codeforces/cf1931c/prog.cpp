#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
void solve(){
    int lp=1,rp;
    cin>>n;
    rp=n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=2;i<=n;++i) if(a[i]==a[i-1]) lp=i; else break;
    for(int i=n-1;i>=1;--i) if(a[i]==a[i+1]) rp=i; else break;
    // cerr<<lp<<" "<<rp<<endl;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    if(lp==n&&rp==1){
        cout<<0<<endl;
        return;
    }
    if(a[1]==a[n]) cout<<rp-lp-1<<endl;
    else cout<<min(n-lp,rp-1)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}