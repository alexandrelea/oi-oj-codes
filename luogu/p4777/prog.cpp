#include <iostream>
using namespace std;
const int SIZE=1e5+10;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0) return x=1,y=0,a;
    else{
        long long res=exgcd(b,a%b,x,y),t=x;
        x=y,y=t-a/b*y;
        return res; 
    }
}
long long mul(long long a,long long b,long long mod){
    long long res=0,base=a;
    for(;b!=0;b/=2,base=base*2%mod) if(b%2==1) res=(res+base)%mod;
    return res;
}
long long exCRT(int n,long long *a,long long *b){
    long long m=b[1],ans=a[1];
    for(int i=1;i<=n;i++){
        long long p=((a[i]-ans)%b[i]+b[i])%b[i];
        long long x,y,gcd=exgcd(m,b[i],x,y);
        if(p%gcd!=0) return -1;
        x=mul(x,p/gcd,b[i]/gcd);
        ans+=x*m,m*=b[i]/gcd,ans=(ans%m+m)%m;
    }
    return (ans%m+m)%m;
}
int main(){
    int n;
    long long a[SIZE],b[SIZE];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
    cout<<exCRT(n,a,b)<<endl;
    return 0;
}