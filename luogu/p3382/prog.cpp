#include<bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
using namespace std;
const double EPS=1e-8;
int n;
double l,r,coef[20],dcof[20],ans;
double Dxf(double x){
    double ans=0;
    for(int i=n-1;i>=0;--i) ans=ans*x+dcof[i];
    return ans;
}
int main(){
    cin>>n>>l>>r;
    for(int i=n;i>=0;--i) cin>>coef[i];
    for(int i=n-1;i>=0;--i) dcof[i]=coef[i+1]*(i+1);
    while(r-l>=EPS){
        double m=(l+r)/2.0,dxf=Dxf(m);
        if(dxf<EPS) ans=m;
        if(dxf<0) r=m;
        else l=m;
    }
    cout<<fs(5)<<ans<<endl;
    return 0;
}