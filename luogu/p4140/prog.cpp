#include <iostream>
#include <iomanip>
#include <string>
#define int long long
using namespace std;
const int SIZE=4e5+10;
const int MOD=19961993;
int n,q,a[SIZE],prt[310],cnt=0,tpr[310],maxu=0,inv[310];
int sum[SIZE*4],mul[SIZE*4];
int mult(int a,int b,int p){
    return a*b%p;
}
int pow(int a,int b,int p){
    int ans=1ll;
    for(;b;b>>=1ll,a=a*a%p) if(b&1ll) ans=ans*a%p;
    return ans;
}
int dive(int a,int b,int p){
    return mult(a,inv[b],p);
}
bool isprime(int x){
    if(x==2) return true;
    if(x<=1||x%2==0) return false;
    for(int i=3;i*i<=x;i+=2) if(x%i==0) return false;
    return true;
}
void pushup(int co){
    sum[co]=sum[co*2]|sum[co*2+1];
    mul[co]=mult(mul[co*2],mul[co*2+1],MOD);
    // cout<<"pushup "<<co<<" "<<co*2<<" "<<co*2+1<<endl;
}
void build(int co,int lef,int rih){
    // cout<<co<<" = ["<<lef<<","<<rih<<"]"<<endl;
    maxu=max(maxu,co);
    if(lef==rih){
        mul[co]=a[lef];
        for(int i=0;i<62;i++) if(a[lef]%tpr[i]==0) sum[co]|=(1ll<<i);
        return;
    }
    int mid=lef+(rih-lef)/2;
    build(co*2,lef,mid),build(co*2+1,mid+1,rih);
    pushup(co);
}
int querypf(int co,int lef,int rih,int ql,int qr){
    if(ql<=lef&&rih<=qr) return sum[co];
    int ans=0,mid=lef+(rih-lef)/2;
    if(ql<=mid) ans|=querypf(co*2,lef,mid,ql,qr);
    if(mid<qr) ans|=querypf(co*2+1,mid+1,rih,ql,qr);
    return ans;
}
int querymul(int co,int lef,int rih,int ql,int qr){
    if(ql<=lef&&rih<=qr) return mul[co];
    int ans=1,mid=lef+(rih-lef)/2;
    if(ql<=mid) ans=mult(ans,querymul(co*2,lef,mid,ql,qr),MOD);
    if(mid<qr) ans=mult(ans,querymul(co*2+1,mid+1,rih,ql,qr),MOD);
    return ans;
}
void modify(int co,int lef,int rih,int ml,int mr,int mv){
    if(lef==rih){
        int sm=0;
        for(int i=0;i<62;i++) if(mv%tpr[i]==0) sm|=(1ll<<i);
        sum[co]=sm;
        mul[co]=mv;
        return;
    }
    // pushdown(co,lef,rih);
    int mid=lef+(rih-lef)/2;
    if(ml<=mid) modify(co*2,lef,mid,ml,mr,mv);
    if(mid<mr) modify(co*2+1,mid+1,rih,ml,mr,mv);
    pushup(co);
}
signed main(){
    ios::sync_with_stdio(false);
    n=100000;
    cin>>q;
    for(int i=1;i<=n;i++) a[i]=3;
    for(int i=1;i<=300;i++) if(isprime(i)) tpr[cnt++]=i,inv[i]=pow(i,MOD-2,MOD);
    build(1,1,n);
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            long long pr=querypf(1,1,n,b,c),prod=querymul(1,1,n,b,c);
            // cout<<pr<<" "<<prod<<endl;
            for(int i=0;i<62;i++) if(pr&(1ll<<i)) prod=mult(prod,dive(tpr[i]-1,tpr[i],MOD),MOD);
            cout<<prod<<endl;
        }else{
            modify(1,1,n,b,b,c);
        }
    }
    return 0;
}