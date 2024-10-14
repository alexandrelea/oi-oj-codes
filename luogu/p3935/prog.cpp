// 洛谷 P3935 - Calculating
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Q=998244353;
ll query(ll n){
    ll ans=0;
    for(ll i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ans+=(j-i+1)*(n/i)%Q;
        ans+=Q,ans%=Q;
    }
    return (ans+Q)%Q;
}
int main(){
    ll l,r;
    cin>>l>>r;
    cout<<(query(r)-query(l-1)+Q)%Q<<endl;
    return 0;
}