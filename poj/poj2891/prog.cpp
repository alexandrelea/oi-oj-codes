// POJ2891 - Strange Way to Express Integers
// Code by Alexandre Lea
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e7+5;
int n;
ll a[N],r[N];
template<typename inte>
inte gcd(inte a,inte b){
    return b==0?a:gcd(b,a%b);
}
template<typename inte>
void exgcd(inte a,inte b,inte &x,inte &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
template<typename inte>
inte abs(inte x){
    return x>=0?x:-x;
}
template<typename inte>
inte mul(inte a,inte b,inte M){
    inte ans=0;
    for(;b;b>>=1,a<<=1,a%=M) if(b&1) ans+=a,ans%=M;
    return ans;
}
template<typename inte>
inte exCRT(int n,inte a[],inte r[]){
    inte ap=a[1],rp=r[1];
    for(int i=2;i<=n;++i){
        inte aq=a[i],rq=r[i],hp,hq,g=gcd(ap,aq),r=((rq-rp+aq)%aq+aq)%aq,w=ap/g*aq;
        if(r%g!=0) return -1;
        exgcd(ap,aq,hp,hq),hp*=(r/g);
        rp=((mul(hp,ap,w)+rp)%w+w)%w,ap=w;
    }
    return (rp+ap)%ap;
}
int main(){
    while(cin>>n){
        for(int i=1;i<=n;++i) cin>>a[i]>>r[i];
        cout<<exCRT(n,a,r)<<endl;
    }
    return 0;
}
