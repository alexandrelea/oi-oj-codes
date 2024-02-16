#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//bx-ay=2
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main(){
    ll a,b;
    cin>>a>>b;
    a*=-1;
    ll g=gcd(a,b);
    if(2%g!=0) cout<<-1<<endl;
    else{
        a/=g,b/=g;
        ll c=2/g;
        ll x,y;
        exgcd(a,b,y,x);
        cout<<x*c<<" "<<y*c<<endl;
    }
    return 0;
}