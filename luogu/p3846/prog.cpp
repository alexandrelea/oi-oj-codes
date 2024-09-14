// 洛谷P3846 - [TJOI2007] 可爱的质数/【模板】BSGS
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,z,k;
ll pw(ll a,ll b,ll m){
    ll ans=1;
    for(;b;b>>=1,a=a*a%m) if(b&1) ans=ans*a%m;
    return ans;
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
// ONLY for PRIME MODULAR!!!
ll log(ll a,ll b,ll p){
    a%=p,b%=p;
    if(a%p==b%p) return 1;
    if(a==0&&b!=0) return -1;
    if(b==1) return 0;
    ll m=(ll)ceil(sqrt(p)),am=pw(a,m,p);
    map<ll,ll> mem;
    for(int i=0;i<=m;++i) mem[b]=i,b*=a,b%=p;
    b=1;
    for(int i=1;i<=m;++i){
        b=b*am%p;
        if(mem.count(b)) return i*m-mem[b];
    }
    return -1;
}
int main(){
    ll p,b,n,ans;
    cin>>p>>b>>n;
    ans=log(b,n,p);
    if(ans==-1) cout<<"no solution"<<endl;
    else cout<<ans<<endl;
    return 0;
}