#include <bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
using namespace std;
int main(){
    double n;
    while(cin>>n&&n){
        double i;
        for(i=0;(i+1)*(i+1)*(i+1)<=n;++i);
        double dx=(n-i*i*i)/(3*i*i);
        cout<<fs(4)<<i+dx<<endl;
    }
    return 0;
}