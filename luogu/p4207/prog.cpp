#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const static int SIZE=510;
double sqr(double x){
    return x*x;
}
int main(){
    int n;
    double alpha,h[SIZE],r[SIZE];
    double pjx[SIZE];
    double ans=0;

    // true means the circle, false means the line (function).
    bool type[SIZE];
    // board of functions, for final INTEGRATION.
    double bod[SIZE];
    // if we uses circle function y=sqrt(v^2-(x-p)^2), we must record v and the p.
    double v[SIZE],p[SIZE];
    // if we uses the line function y=kx+b, we must record k and b.
    double k[SIZE],b[SIZE];
    // number of functions(in boards).
    int cnt;

    cin>>n>>alpha;
    for(int i=0;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>r[i];

    // below lines for rejection.
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

    // for the first point, we must specify it. (poor eng)
    if(h[1]+r[1]>h[0]){
        bod[1]=h[1]+r[1],type[1]=true;
        p[1]=r[1];
        v[1]=h[1];
    }else{
        bod[1]=h[0],type[1]=false;
        double qt1=sqr(h[0]-h[1])-sqr(r[1]),delh=h[0]-h[1];
        double x=(sqr(r[1])-qt1+sqr(delh))/(2.0*delh)+h[1];
        double p1=sqrt(sqr(r[1])-sqr(x-h[1]));
        // now we have 2 points: (x,p1) and (h[0],0)
        // and we can make 2 linear equations
        // xb+k=p1 and h[0]b+k=0
        // and the unknowns are b and k
        // now we find b=(p*h[0])/(h[0]-x),k=-p1/(h[0]-x)
        bod[2]=x;
        k[1]=-p1/(h[0]-x);
        b[1]=(p1*h[0])/(h[0]-x);
        // we don't know if it is right.
    }
    cnt=1;
    return 0;
}
