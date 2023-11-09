#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-7;
typedef complex<long double> CC;
bool oouted=false;
CC f(CC z,CC c){
    return z*z+c;
}
void solve(){
    if(oouted) cout<<endl;
    string C;
    double mini,maxi,minr,maxr,preci,precr;
    cin>>C>>mini>>maxi>>preci>>minr>>maxr>>precr;
    C[0]=C[13]=' ';
    C.append(30,' ');
    for(long double im=mini;im<=maxi+EPS;im+=preci){
        for(long double re=minr;re<=maxr+EPS;re+=precr){
            CC z=CC(0,0),c=CC(re,im);
            int i=0;
            for(i=1,z=f(z,c);i<=12;i++,z=f(z,c)) if(abs(z)>=2+EPS) break;
            cout<<C[i];
        }
        cout<<endl;
    }
    oouted=true;
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}