// POJ2115 - C Looooops
// Code by Alexandre Lea
#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,c,k,h,K,m,d,g;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main(){
    while(cin>>a>>b>>c>>k&&(a||b||c||k)){
        K=(1ll<<k),d=(b-a+K)%K,g=gcd(c,K);
        if(d%g!=0) cout<<"FOREVER"<<endl;
        else{
            exgcd(c,K,m,h);
            cout<<(d/g*m%(K/g)+(K/g))%(K/g)<<endl;
        }
    }
    return 0;
}
