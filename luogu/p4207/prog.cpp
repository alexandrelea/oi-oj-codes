#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const static int SIZE=510;
const static double EPS=1e-7;
// some initial data (in the problem).
int n;
double alpha,h[SIZE],r[SIZE];
double pjx[SIZE];
double ans=0;

// true means the circle, false means the line (function).
bool type[SIZE];
// board of functions, for final INTEGRATION.
double bod[SIZE];
// if we uses circle function y=sqrt(v^2-(x-p)^2), we must record radius v and the positition p.
double v[SIZE],p[SIZE];
// if we uses the line function y=kx+b, we must record k and b.
double k[SIZE],b[SIZE];
// number of functions(in boards).
int cnt;

// square of a number x.
double sqr(double x){
    return x*x;
}

// circle function (at line 18 comment).
double cirf(double v,double p,double x){
    return sqrt(v*v-sqr(x-p));
}

// use auto simpson to calculate definite integral.
double dI(double v,double p,double lf,double rt){
    double md=(lf+rt)/2;
    double nws=(rt-lf)*(cirf(v,p,lf)+cirf(v,p,rt)+4*cirf(v,p,(lf+rt)/2));
    double lfs=(md-lf)*(cirf(v,p,lf)+cirf(v,p,md)+4*cirf(v,p,(lf+md)/2));
    double rts=(rt-md)*(cirf(v,p,md)+cirf(v,p,rt)+4*cirf(v,p,(md+rt)/2));
    if(fabs(lfs+rts-nws)<EPS) return nws;
    else return dI(v,p,lf,md)+dI(v,p,md,rt);
}

//definite Integral (not simpson!).
double dI(int bd){
    if(!type[bd]){
        double lbf=bod[bd]*k[bd]+b[bd],rbf=bod[bd+1]*k[bd]+b[bd];
        return (lbf+rbf)*(bod[bd]-bod[bd+1])/2.0;
    }else{
        // calculate function y=sqrt(v[bd]^2-(x-p[bd])^2) from bod[bd] to bod[bd+1].
        return dI(v[bd],p[bd],bod[bd],bod[bd+1]);
    }
}
int main(){
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
        cout<<dI(1)<<endl;
    }
    cnt=1;
    // now we've found two point (h[i],0) and (h[i+1],0)
    // and two circles r[i],r[i+1]
    // we can found a point 
    
    for(int i=1;i<=n;i++){
        // Ahh we can only look two circles! and we can add the last connect!! new hope!
        // now we have 2 points on the x-axis: (0,h[i+1]) and (0,h[i]) and radius r[i+1] and r[i]
        // and we can get the hypot... hy=sqrt((h[i+1]-h[i])^2-(r[i+1]-r[i])^2) and like the first we can got two points
        double delh=fabs(h[i+1]-h[i]),delr=fabs(r[i+1]-r[i]),nx,ny,hyp=sqrt(sqr(h[i+1]-h[i])-sqr(r[i+1]-r[i])),hx=0,hy=0;
        // and now we get x=(hyp^2+delh^2-delr^2)/(2delh),for y we can throw it in the circle function.
        nx=(sqr(hyp)+sqr(delh)-sqr(delr))/(2*delh);
        
        // because a prallel quad, we must add (nx,ny) and (0,hx) a vector (x,y).
        // but, the vector is not clear now.
        // two points (nx+delx,ny+dely) and (delx,hy+dely) must specify two circle functions.
        // so we can only find nx....?
        if(r[i+1]>r[i]){
            ny=cirf(r[i+1],h[i+1],nx),hy=h[i];
            double nnx=nx,nny=ny;
            // (nnx,nny) is on the line of (nx,ny) and (0,h[i+1]) same for next if :-)
            // but it may perp the x-axis :-O
            // ahaha now we get the new line y=((ny)/(nx-h[i]))x+((h[i]*ny)/(h[i]-nx))
            // we must find the root of line and the circle. we will find the root tomorrow :-) bye!
        }else ny=cirf(r[i],h[i],nx),hy=h[i+1];
    }
    return 0;
}
/*
首先我们将各个半圆方程倒序列在 $x$ 轴上。

而后我们需要将部分直线一段一段替换部分圆方程。

最后对整个函数进行积分。至于怎么积，辛普森罢。

这就是大体的思路了。

首先，如果最后的点嵌入了，那么三角就没有必要算了。

而后，对于两个圆的画，我们的任务是二分求每个 $x$.
*/
