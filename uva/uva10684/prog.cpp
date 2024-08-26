// UVa10684 - The jackpot
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a,S,ans;
int main(){
    while(cin>>n&&n){
        S=ans=0;
        for(int i=1;i<=n;++i){
            cin>>a;
            S=max(0,S+a);
            ans=max(ans,S);
        }
        if(ans>0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;
        else cout<<"Losing streak."<<endl;
    }
    return 0;
}