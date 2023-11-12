#include <bits/stdc++.h>
using namespace std;
double EPS=1e-6;
int n;
double f[10],f_[10],g[10],g_[10],z[10];
double fc(double x){
    double ans=0;
    for(int i=n;i>=0;--i) ans=ans*x+f[i];
    return ans;
}
double f_c(double x){
    double ans=0;
    for(int i=n-1;i>=0;--i) ans=ans*x+f_[i];
    return ans;
}
double newton(double z){
    while(fabs(fc(z))>=EPS) z-=fc(z)/f_c(z);
    for(int i=n-1;i>=0;--i) g[i]=f[i+1]*z,f[i]+=f[i+1]*z;
    for(int i=0;i<=n-1;++i) f[i]=g[i];
    --n;
    for(int i=n-1;i>=0;--i) f_[i]=f[i+1]*double(i+1);
    return z;
}
int main(){
    int _=0;
    while(cin>>n&&n!=0){
        int m=n;
        for(int i=n;i>=0;--i) cin>>f[i];
        for(int i=n-1;i>=0;--i) f_[i]=f[i+1]*double(i+1);
        cout<<"Equation "<<(++_)<<": ";
        for(int i=1;i<=m;i++) z[i]=newton(0);
        sort(z+1,z+m+1);
        for(int i=1;i<=m;i++) cout<<fixed<<setprecision(4)<<z[i]<<(i==m?'\n':' ');
        cout<<flush;
    }
    return 0;
}