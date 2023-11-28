#include <bits/stdc++.h>
using namespace std;
const int L=18,N=1<<L;
const double PI=acos(-1);
int n,l=0,p=1;
complex<double> f[N],g[N],eps[N],ieps[N];
void fft(int n,complex<double> x[],complex<double> w[]){
    for(int i=0,j=0;i!=n;++i){
        if(i>j) swap(x[i],x[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=n;i<<=1){
        int m=i>>1;
        for(int j=0;j<n;j+=i) for(int k=0;k!=m;++k){
            complex<double> z=x[j+m+k]*w[n/i*k];
            x[j+m+k]=x[j+k]-z;
            x[j+k]+=z;
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    while(p<n) ++l,p<<=1;
    ++l,p<<=1;
    for(int i=0;i!=p;++i) f[i]=g[i]=0;
    for(int i=0;i!=n;++i){
        double x;
        cin>>x;
        f[i]=x;
    }
    for(int i=0;i+1<n;++i) g[i]=1.0/((n-i-1.0)*(n-i-1.0)),g[2*n-i-2]=-g[i];
    for(int i=0;i<p;++i) eps[i]=complex<double>(cos(2.0*PI*i/p),sin(2.0*PI*i/p));
    for(int i=0;i<p;++i) ieps[i]=conj(eps[i]);
    reverse(g,g+p);
    fft(p,f,eps),fft(p,g,eps);
    for(int i=0;i<p;++i) f[i]*=g[i];
    fft(p,f,ieps);
    for(int i=p-n;i!=p;++i) cout<<fixed<<setprecision(3)<<f[i].real()/p<<endl;
    return 0;
}