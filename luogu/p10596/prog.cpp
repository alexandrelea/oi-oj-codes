// 洛谷 P10596 - BZOJ2839 集合计数
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1'000'005,O=1'000'000'007;
ll n,k,ppw[N],ft[N],ift[N],f[N];
ll pw(ll a,ll b,ll p){
    ll ans=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) ans=ans*a%p;
    return ans;
}
ll C(ll n,ll m){
    if(m>n) return 0;
    return (ft[n]*ift[m]%O)*ift[n-m]%O;
}
int main(){
    cin>>n>>k;
    ft[0]=ift[0]=1;
    ppw[0]=2;
    for(ll i=1;i<=n;++i){
        ppw[i]=ppw[i-1]*ppw[i-1]%O;
        ft[i]=ft[i-1]*i%O;
        ift[i]=ift[i-1]*pw(i,O-2,O)%O;
    }
    ll ans=0;
    for(ll i=k;i<=n;++i){
        ans+=((((i-k)%2==0?1:-1)*C(i,k)%O+O)%O*C(n,i)%O*(ppw[n-i]-1)%O);
        ans%=O,ans+=O,ans%=O;
    }
    cout<<ans<<endl;
    return 0;
}