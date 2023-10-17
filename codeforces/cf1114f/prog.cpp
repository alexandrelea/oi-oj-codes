#include <iostream>
#include <iomanip>
#include <string>
#define int long long
using namespace std;
const int SIZE=4e5+10;
const int MOD=1e9+7;
int n,q,a[SIZE],prt[310],cnt=0,tpr[310],maxu=0,inv[310];
int sum[SIZE*4],tag[SIZE*4],mul[SIZE*4],tmg[SIZE*4];
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
void pushdown(int co,int lef,int rih){
    // if(tmg[co]==1&&tag[co]==0) return;
    int mid=lef+(rih-lef)/2;
    sum[co*2]|=tag[co],sum[co*2+1]|=tag[co];
    tag[co*2]|=tag[co],tag[co*2+1]|=tag[co],tag[co]=0;

    mul[co*2]=mult(mul[co*2],pow(tmg[co],mid-lef+1,MOD),MOD),
    mul[co*2+1]=mult(mul[co*2+1],pow(tmg[co],rih-mid,MOD),MOD);
    tmg[co*2]=mult(tmg[co*2],tmg[co],MOD),
    tmg[co*2+1]=mult(tmg[co*2+1],tmg[co],MOD),tmg[co]=1;
}
void pushup(int co){
    sum[co]=sum[co*2]|sum[co*2+1];
    mul[co]=mult(mul[co*2],mul[co*2+1],MOD);
    // cout<<"pushup "<<co<<" "<<co*2<<" "<<co*2+1<<endl;
}
void build(int co,int lef,int rih){
    // cout<<co<<" = ["<<lef<<","<<rih<<"]"<<endl;
    tmg[co]=1,tag[co]=0;
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
    pushdown(co,lef,rih);
    int ans=0,mid=lef+(rih-lef)/2;
    if(ql<=mid) ans|=querypf(co*2,lef,mid,ql,qr);
    if(mid<qr) ans|=querypf(co*2+1,mid+1,rih,ql,qr);
    return ans;
}
int querymul(int co,int lef,int rih,int ql,int qr){
    if(ql<=lef&&rih<=qr) return mul[co];
    pushdown(co,lef,rih);
    int ans=1,mid=lef+(rih-lef)/2;
    if(ql<=mid) ans=mult(ans,querymul(co*2,lef,mid,ql,qr),MOD);
    if(mid<qr) ans=mult(ans,querymul(co*2+1,mid+1,rih,ql,qr),MOD);
    return ans;
}
void modify(int co,int lef,int rih,int ml,int mr,int mv){
    if(ml<=lef&&rih<=mr){
        int sm=0;
        for(int i=0;i<62;i++) if(mv%tpr[i]==0) sm|=(1ll<<i);
        sum[co]|=sm,tag[co]|=sm;
        mul[co]=mult(mul[co],pow(mv,rih-lef+1,MOD),MOD),tmg[co]=mult(tmg[co],mv,MOD);
        return;
    }
    pushdown(co,lef,rih);
    int mid=lef+(rih-lef)/2;
    if(ml<=mid) modify(co*2,lef,mid,ml,mr,mv);
    if(mid<mr) modify(co*2+1,mid+1,rih,ml,mr,mv);
    pushup(co);
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=300;i++) if(isprime(i)) tpr[cnt++]=i,inv[i]=pow(i,MOD-2,MOD);
    build(1,1,n);
    while(q--){
        string op;
        int l,r,x;
        cin>>op>>l>>r;
        if(op=="TOTIENT"){
            int c=querypf(1,1,n,l,r),toti=querymul(1,1,n,l,r);
            for(int i=0;i<62;i++) if(c&(1ll<<i)) toti=mult(toti,dive(tpr[i]-1,tpr[i],MOD),MOD);
            cout<<toti<<endl;
        }else{
            cin>>x;
            modify(1,1,n,l,r,x);
        }
    }
    return 0;
}