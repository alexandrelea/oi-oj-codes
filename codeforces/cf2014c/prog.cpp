// Codeforces 2014C - Robin Hood in Town
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],S;
int solve(){
    S=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],S+=a[i];
    sort(a+1,a+n+1);
    if(n<3) return -1;
    // a[n/2]*n*2<S+x
    // x>a[n/2]*n*2-S
    return max(0ll,a[n/2+1]*n*2-S+1);
}
signed main(){
    int _;
    cin>>_;
    while(_--) cout<<solve()<<endl;
    return 0;
}