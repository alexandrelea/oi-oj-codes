#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6,P=167772161,gP=3;
int n,m,h,nu,ju[(N<<2)+10];
int a[(N<<2)+10],b[(N<<2)+10],c[(N<<2)+10];
int pow(int a,int b,int p){
    int ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%p;
        a=a*a%p;
    }
    return ans;
}
void pre(int l){
    for(int i=0;i<l;++i){
        ju[i]=ju[i>>1]>>1;
        if(i&1) ju[i]|=l>>1;
    }
}
const int gPinv=pow(gP,P-2,P);
void ntt(int f[],int l,int re){
    for(int i=0;i<l;++i) if(i<ju[i]) swap(f[i],f[ju[i]]);
    for(int i=2;i<=l;i<<=1){
        int step=pow(re==1?gP:gPinv,(P-1)/i,P);
        for(int j=0;j<l;j+=i){
            int cur=1;
            for(int k=j;k<j+i/2;++k){
                int u=f[k],v=f[k+i/2]*cur%P;
                f[k]=(u+v)%P,f[k+i/2]=(u-v+P)%P;
                cur=cur*step%P;
            }
        }
    }
    if(re==-1){
        int linv=pow(l,P-2,P);
        for(int i=0;i<l;++i) f[i]=f[i]*linv%P;
    }
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<=n;++i) cin>>a[i],a[i]%=P;
    for(int i=0;i<=m;++i) cin>>b[i],b[i]%=P;
    for(h=2;h<=n+m;h<<=1);
    pre(h);
    ntt(a,h,1),ntt(b,h,1);
    for(int i=0;i<h;++i) c[i]=a[i]*b[i]%P;
    ntt(c,h,-1); 
    for(int i=0;i<=n+m;++i) cout<<c[i]<<" ";
    return 0;
}