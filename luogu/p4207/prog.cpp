// WAed on 2023/10/2 21:44.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const static int SIZE=510;
int main(){
    int n;
    double alpha,h[SIZE],r[SIZE];
    double pjx[SIZE];
    double ans=0;
    cin>>n>>alpha;
    for(int i=0;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>r[i];
    double talp=tan(alpha),hh=h[0];
    for(int i=1;i<=n;i++){
        pjx[i]=hh/talp;
        hh+=h[i];
    }
    pjx[n+1]=hh/talp;
    for(int i=1;i<=n+1;i++) h[i]=pjx[i];
    reverse(h+1,h+n+2);
    reverse(r+1,r+n+1);
    for(int i=0;i<=n+1;i++) h[i]=h[i+1];
    for(int i=0;i<=n+1;i++) cout<<h[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n+1;i++) cout<<r[i]<<" ";
    cout<<endl;
    double agl=acos(fabs(r[1]-r[0])/fabs(h[1]-h[0])),agr=acos(fabs(r[2]-r[1])/fabs(h[2]-h[1]));
    for(int i=1;i<=n;i++){
        // trapezoid for h[i-1] and h[i]
        double dfr=fabs(r[i]-r[i-1]),dfh=h[i]-h[i-1];
        ans+=sqrt(fabs(dfh*dfh-dfr*dfr))*(r[i]+r[i-1]);
        // calculate sections
        if(i==n) agr=0;
        if(i==n) ans+=(M_PI-agl-agr)*r[i]*r[i];
        else ans+=(M_PI-agl-agr)*r[i]*r[i];
        agl=M_PI-agr,agl+=M_PI/2;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
