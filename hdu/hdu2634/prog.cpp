#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long double su=0,val=0;
        for(int i=1;i<=n;++i) cin>>val,su+=val;
        cout<<"The average M = "<<fixed<<setprecision(10)<<su/(long double)n<<"."<<endl;
    }
    return 0;
}