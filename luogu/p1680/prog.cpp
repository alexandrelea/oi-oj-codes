// LG1680 - 奇怪的分组
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1'0000'0000'7; // thanks for @ScaredQiu, who told this usage for me
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll C(ll a,ll b){
    if(b>a) return 0;
    ll up=1,dn=1,idn,tmp;
    for(ll i=b+1;i<=a;++i) up*=i,up%=M;
    for(ll i=1;i<=a-b;++i) dn*=i,dn%=M;
    exgcd(dn,M,idn,tmp),idn+=M,idn%=M;
    cerr<<"(("<<a<<","<<b<<"))="<<(up*idn%M+M)%M<<endl;
    return (up*idn%M+M)%M;
}
ll comb(ll a,ll b){
    if(b==0) return 1;
    return (C(a%M,b%M)*comb(a/M,b/M)%M+M)%M;
}
int main(){
    int n,m,c;
    cin>>n>>m;
    for(int i=1;i<=m;++i) cin>>c,n-=c;
    cout<<comb(n-1,m-1)<<endl;
    return 0;
}