// LG3807 - 卢卡斯定理/Lucas 定理
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll C(ll a,ll b,ll m){
    if(b>a) return 0;
    ll num=1,deno=1,ideno,tmp;
    for(ll i=b+1;i<=a;++i) num=num*i%m;
    for(ll i=1;i<=a-b;++i) deno=deno*i%m;
    exgcd(deno,m,ideno,tmp),ideno+=m,ideno%=m;
    return (num*ideno%m+m)%m;
}
ll comb(ll a,ll b,ll m){
    if(b==0) return 1;
    return (C(a%m,b%m,m)*comb(a/m,b/m,m)%m+m)%m;
}
int main(){
    int _;
    cin>>_;
    while(_--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<comb(a+b,a,m)<<endl;
    }
    return 0;
}