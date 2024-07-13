#include <bits/stdc++.h>
using namespace std;
double dist2(double x0,double y0,double x1,double y1){
    double dx=x0-x1,dy=y0-y1;
    return dx*dx+dy*dy;
}
int main(){
    double ax,ay,bx,by,cx,cy,ab,bc,ac;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    ab=dist2(ax,ay,bx,by);
    bc=dist2(bx,by,cx,cy);
    ac=dist2(ax,ay,cx,cy);
    if(ab+bc==ac||ab+ac==bc||ab==ac+bc) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}