#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-8;
double p,q,r,s,t,u,lf,rt,mi,wtf;
double f(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
}
int main(){
    while(cin>>p>>q>>r>>s>>t>>u){
        lf=0;
        rt=1;
        for(int i=1;i<=50;i++){
            mi=(lf+rt)/2.0;
            wtf=f(mi);
            if(fabs(wtf)<EPS) break;
            else if(wtf>0) lf=mi;
            else rt=mi;
        }
        if(fabs(f(mi))<EPS) cout<<fixed<<setprecision(4)<<mi<<endl;
        else cout<<"No solution"<<endl;
    }
    return 0;
}
