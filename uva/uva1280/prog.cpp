#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const static double EPS=1e-9;
struct polymial{
    double co[21];
    polymial(){
        for(int i=0;i<=20;i++) co[i]=0.00;
    }
    polymial sq(){
        polymial p;
        for(int i=0;i<=10;i++) for(int j=0;j<=10;j++) p.co[i+j]+=co[i]*co[j];
        return p;
    }
    double cmpu(int pw,double a,double b){
        return pow(b,pw)-pow(a,pw);
    }
    double rotv(double xlow,double xhigh){
        double v=0.0;
        for(int i=0;i<=20;i++) v+=co[i]*cmpu(i+1,xlow,xhigh)/(double)(i+1);
        return v*M_PI;
    }
};
double plm(polymial p,double xlow,double xhigh,double inc){
    double base=xlow,v=0.0;
    while(fabs(xhigh-xlow)>EPS){
        double mid=(xlow+xhigh)/2.0;
        v=p.rotv(base,mid);
        if(v<inc) xlow=mid;
        else xhigh=mid;
    }
    if(fabs(v-inc)>1e-5) return -10000;
    return xlow;
}
int main(){
    int n,tc=1;
    while(cin>>n){
        double xlow,xhigh,inc;
        polymial p=polymial();
        int idx=0;
        for(int i=0;i<=n;i++) cin>>p.co[i];
        p=p.sq();
        cin>>xlow>>xhigh>>inc;
        double xcur=xlow,marks[10]={};
        while(idx<8){
            double mark=plm(p,xcur,xhigh,inc);
            if(mark<-1000) break;
            xcur=mark;
            marks[idx++]=mark-xlow;
        }
        cout<<"Case "<<(tc++)<<": "<<fixed<<setprecision(2)<<p.rotv(xlow,xhigh)<<endl;
        if(idx==0) cout<<"insufficient volume"<<endl;
        else{
            for(int i=0;i<idx-1;i++) cout<<fixed<<setprecision(2)<<marks[i]<<" ";
            cout<<marks[idx-1]<<endl;
        }
    }
    return 0;
}