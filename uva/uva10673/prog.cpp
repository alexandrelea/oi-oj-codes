#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=(a/b)*x;
}
int main(){
    int _;
    cin>>_;
    while(_--){
        ll x,k,a,b,p,q,g;
        cin>>x>>k;
        a=x/k,b=x/k+!!(x%k),g=gcd(a,b);
        // cerr<<a<<"p+"<<b<<"q="<<x<<",("<<a<<","<<b<<")="<<g<<endl;
        exgcd(a,b,p,q);
        cout<<p*(x/g)<<" "<<q*(x/g)<<endl;
    }
    return 0;
}