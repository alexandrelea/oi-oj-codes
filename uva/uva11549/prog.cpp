// UVa11549 - Calculator Conundrum
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll sqmn(ll x){
    ll ans=x*x;
    while(ans>=n) ans/=10;
    return ans;
}
void solve(){
    cin>>n>>k;
    n=pow(10,n);
    ll k1=k,k2=k,ans=k;
    do{
        k1=sqmn(k1);
        k2=sqmn(k2),ans=max(ans,k2);
        k2=sqmn(k2),ans=max(ans,k2);
    }while(k1!=k2);
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}