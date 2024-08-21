// LG4777 - 【模板】扩展中国剩余定理（EXCRT）
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const int N=1e7+5;
int n;
ll v;
i128 a[N],r[N];
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
inte exCRT(int n,inte a[],inte r[]){
    inte ap=a[1],rp=r[1];
    for(int i=2;i<=n;++i){
        inte aq=a[i],rq=r[i],hp,hq,g=gcd(ap,aq),r=((rq-rp+aq)%aq+aq)%aq;
        if(r%g!=0) return -1;
        exgcd(ap,aq,hp,hq),hp*=(r/g);
        rp=hp*ap+rp,ap*=(aq/g);
        rp=((rp+ap)%ap+ap)%ap;
    }
    return (rp+ap)%ap;
}
int main(){
    while(cin>>n){
        for(int i=1;i<=n;++i) cin>>v,a[i]=v,cin>>v,r[i]=v;
        cout<<(v=exCRT(n,a,r))<<endl;
    }
    return 0;
}