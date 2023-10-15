#include <iostream>
#include <cmath>
#define int __int128_t
using namespace std;
const int MOD=998244353;
int sqr(int x){
    return x*x;
}
int pow(int a,int b,int p){
    int ans=1;
    for(;b;b>>=1,a=a*a%p) if(b%2==1) ans=ans*a%p;
    return ans;
}
int inv(int x){
    return pow(x,MOD-2,MOD);
}
signed main(){
    long long v;
    int a,aa,b,tot=1,inv2=inv(2);
    bool flg=false;
    cin>>v,aa=a=v,cin>>v,b=v;
    for(int i=2;i*i<=aa;i++){
        if(a%i==0){
            int cnt=0;
            while(a%i==0) cnt++,a/=i;
            tot*=(cnt*b+1),tot%=MOD;
        }
        if(i*i==aa) flg=true;
    }
    if(a!=1) tot*=(b+1),tot%=MOD;
    if(flg||b%2==0) v=((((tot-1+MOD)*inv2%MOD*b%MOD)%MOD+(b/2)%MOD)%MOD),cout<<v<<endl;
    else v=((tot*inv2%MOD*b%MOD)%MOD),cout<<(long long)v<<endl;
    return 0;
}