#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,k;
    cin>>n;
    k=(1+sqrt(8*n+1))/2;
    cout<<n+k-k*(k-1)/2<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}