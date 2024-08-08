#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        double a,b,s,ans;
        cin>>a>>b>>s;
        double m=a*b;
        if(fabs(s)<1e-6) ans=1;
        else if(s>m) ans=0;
        else ans=m-s-s*log(m/s),ans/=m;
        cout<<fixed<<setprecision(6)<<100*ans<<"%"<<endl;
    }
    return 0;
}