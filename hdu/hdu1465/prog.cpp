// HDU 1465 - 不容易系列之一
// Code by Alexandre Lea
#include <iostream>
using namespace std;
typedef long long ll;
ll ft(ll x){
    return x==0?1ll:ft(x-1)*x;
}
ll C(ll n,ll m){
    ll ans=ft(n)/ft(m)/ft(n-m);
    return ans;
}
int main(){
    ll n;
    while(cin>>n){
        // the most:g(n)=n!
        // exactly: f(n)
        // fit g(n)=sum[i=0...n]C(n,i)f(i)
        // so f(n)=sum[i=0...n]C(n,i)(-1)^(n-i)g(i)
        ll ans=0;
        for(ll i=0;i<=n;++i) ans+=C(n,i)*((n-i)%2==1?-1:1)*ft(i);
        cout<<ans<<endl;
    }
    return 0;
}