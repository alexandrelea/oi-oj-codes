#include <bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
using namespace std;
const double PI=acos(-1),EPS=1e-7;
const int N=1e5+10,K=100;
vector<complex<double>> omg,comg;
complex<double> a[N*4],b[N*4];
int n,m,k;
void fft(complex<double> a[],int n,int invt){
    if(n==1) return;
    int m=n/2;
    complex<double> a1[m+1],a2[m+1];
    for(int i=0;i<=n;i+=2) a1[i/2]=a[i],a2[i/2]=a[i+1];
    fft(a1,m,invt),fft(a2,m,invt);
    complex<double> w0(1,0),wn(cos(2*PI/n),invt*sin(2*PI/n));
    for(int i=0;i<m;++i,w0*=wn) a[i]=a1[i]+w0*a2[i],a[i+n/2]=a1[i]-w0*a2[i];
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;++i){
        double x;
        cin>>x;
        a[i].real(x);
    }
    for(int i=0;i<=m;++i){
        double x;
        cin>>x;
        b[i].real(x);
    }
    for(k=2;k<=n+m;k<<=1);
    fft(a,k,1),fft(b,k,1);
    for(int i=0;i<=k;++i) a[i]=a[i]*b[i];
    fft(a,k,-1);
    for(int i=0;i<=n+m;++i) cout<<fs(0)<<(a[i].real()/k+EPS)<<" ";
    return 0;
}