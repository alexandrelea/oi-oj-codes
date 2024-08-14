// POJ3061 - Subsequence
// Code by Alexanderia Lea
#include <iostream>
using namespace std;
const int N=1e5+5;
int n;
long long a[N],S;
void solve(){
    cin>>n>>S;
    for(int i=1;i<=n;++i) cin>>a[i];
    int lp=1,rp=0,ans=n+1;
    long long s=0;
    while(lp<=n&&rp<=n){
        while(s<S&&rp<n) s+=a[++rp];
        if(s>=S) ans=min(ans,rp-lp+1);
        s-=a[lp++];
    }
    cout<<(ans<=n?ans:0)<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}