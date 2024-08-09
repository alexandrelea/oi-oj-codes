#include <iostream>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
const static int SIZE=1e5+10,MOD=999911659;
int n,g;
vector<int> primes;
int fac(int n,int p){
    if(n==0) return 1;
    else return n*fac(n-1,p)%p;
}
int qpow(int a,int b,int p){
    if(a==1||(a==0&&b!=0)) return 1;
    if(b==1) return a%p;
    int c=qpow(a*a%p,b/2,p)%p;
    if(b%2==1) c=c*a%p;
    return c%p;
}
int bimo(int n,int m,int p){
    if(m>n) return 0;
    if(m==0) return 1;
    if(m>n-m) m=n-m;
    return (fac(n,p)*qpow(fac(m,p),p-2,p)%p)*qpow(fac(n-m,p),p-2,p)%p;
}
int biom(int n,int m,int p){
    if(m==0) return 1;
    return bimo(n%p,m%p,p)*biom(n/p,m/p,p)%p;
}
int biom(int nn,int mm){
    int a[5]={0,biom(nn,mm,2),biom(nn,mm,3),biom(nn,mm,4679),biom(nn,mm,35617)};
    int n[5]={999911658,2,3,4679,35617},m[5],im[5],c[5],x=0;
    for(int i=1;i<=4;i++) m[i]=n[0]/n[i];
    for(int i=1;i<=4;i++) im[i]=qpow(m[i],n[i]-2,n[i]);
    for(int i=1;i<=4;i++) c[i]=m[i]*im[i];
    for(int i=1;i<=4;i++) x=(x+a[i]*c[i]+n[0])%n[0];
    return x;
}
signed main(){
    cin>>n>>g;
    if(g%MOD==0){
        cout<<0<<endl;
        return 0;
    }
    int ep=0;
    for(int p=1;p*p<=n;p++){
        if(n%p==0){
            ep=(ep+biom(n,n/p))%(MOD-1);
            if(p!=n/p) ep=(ep+biom(n,p))%(MOD-1);
        }
    }
    cout<<qpow(g,ep,MOD)<<endl;
    return 0;
}