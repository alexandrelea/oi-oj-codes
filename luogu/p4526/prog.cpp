#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const long double eps=1e-10;
long double a;
long double f(long double x){
    return pow(x,a/x-x);
}
long double simp(double l,double r){
    return (r-l)/6*(f(l)+f(r)+4*f((l+r)/2));
}
long double itg(double l,double r){
    double m=(l+r)*0.5,ig1=simp(l,m),ig2=simp(m,r),ig0=simp(l,r);
    if(fabs(ig1+ig2-ig0)<eps) return ig0;
    else return itg(l,m)+itg(m,r);
}
int main(){
    cin>>a;
    if(a<0) cout<<"orz"<<endl;
    else cout<<fixed<<setprecision(5)<<itg(eps,20)<<endl;
    return 0;
}