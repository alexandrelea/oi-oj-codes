// UVa1388 - Graveyard
// Code by Lea Alexanderia
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        double ans=0;
        for(int i=1;i<n;++i){
            double pos=(double)i/n*(n+m);
            ans+=fabs(pos-floor(pos+0.5))/(n+m);
        }
        cout<<fixed<<setprecision(4)<<ans*10000<<endl;
    }
    return 0;
}