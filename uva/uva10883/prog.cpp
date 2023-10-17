#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
long double sgn(long double x){
    if(x>0) return 1.0;
    if(x<0) return -1.0;
    return 0.0;
}
void maintain(int __){
    int n;
    long double a[50010],ans=0.0,lbinom=0.0;
    cin>>n,n--;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++){
        ans+=sgn(a[i])*pow(2.0,lbinom+log2(fabs(a[i]))-n);
        // binom*=(n-i),binom/=(i+1);
        lbinom+=log2((double)(n-i)/(double)(i+1));
    }
    // cout<<endl;
    cout<<"Case #"<<__<<": "<<fixed<<setprecision(3)<<ans<<endl;
}
int main(){
    int t,_=0;
    cin>>t;
    while(t--) maintain(++_);
    return 0;
}