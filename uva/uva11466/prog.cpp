// UVa11466 - Largest Prime Divisor
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll x){
    ll n=x,m=0,ans,h=0;
    for(ll i=2;i*i<=x;++i){
        if(n%i==0) ++h;
        while(n%i==0) n/=i,m=max(m,i);
    }
    if(n==1) ans=m;
    else ans=n,++h;
    if(h==1||x==1) return -1;
    else return ans;
}
int main(){
    ll n;
    while(cin>>n&&n) cout<<solve(abs(n))<<endl;
    return 0;
}