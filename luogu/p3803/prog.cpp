#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
const double pi=acos(-1);
struct clex{
    double re,im;
    clex(double re=0,double im=0):re(re),im(im){}
    clex operator+(const clex &rhs)const{
        return clex(re+rhs.re,im+rhs.im);
    }
    clex operator-(const clex &rhs)const{
        return clex(re-rhs.re,im-rhs.im);
    }
    clex operator*(const clex &rhs)const{
        return clex(re*rhs.re-im*rhs.im,re*rhs.im+im*rhs.re);
    }
    clex operator/(const double &rhs)const{
        return clex(re/rhs,im/rhs);
    }
};
int n,m,h,nu,ju[(N<<2)+10];
clex a[(N<<2)+10],b[(N<<2)+10],c[(N<<2)+10];
void pre(int l){
    memset(ju,0,sizeof ju);
    for(int i=0;i<l;++i){
        ju[i]=ju[i>>1]>>1;
        if(i&1) ju[i]|=l>>1;
    }
}
void fft(clex f[],int l,int re){
    for(int i=0;i<l;++i) if(i<ju[i]) swap(f[i],f[ju[i]]);
    for(int i=2;i<=l;i<<=1){
        double th=2*pi/(double)i;
        clex step=clex(cos(th),re*sin(th));
        for(int j=0;j<l;j+=i){
            clex cur=clex(1,0);
            for(int k=j;k<j+i/2;++k){
                clex u=f[k],v=f[k+i/2]*cur;
                f[k]=u+v,f[k+i/2]=u-v;
                cur=cur*step;
            }
        }
    }
    if(re==-1) for(int i=0;i<l;++i) f[i]=f[i]/(double)l;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;++i) cin>>nu,a[i]=clex(nu,0);
    for(int i=0;i<=m;++i) cin>>nu,b[i]=clex(nu,0);
    for(h=2;h<=n+m;h<<=1);
    pre(h);
    fft(a,h,1),fft(b,h,1);
    for(int i=0;i<h;++i) c[i]=a[i]*b[i];
    fft(c,h,-1); 
    for(int i=0;i<=n+m;++i) cout<<fixed<<setprecision(0)<<(int)(c[i].re+0.5)<<" ";
    return 0;
}