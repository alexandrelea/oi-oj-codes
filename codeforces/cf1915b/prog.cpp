#include <bits/stdc++.h>
using namespace std;
void solve(){
    char abc[4][4];
    int qi,qj;
    for(int i=1;i<=3;++i) for(int j=1;j<=3;++j){
        cin>>abc[i][j];
        if(abc[i][j]=='?') qi=i,qj=j;
    }
    int sum=0+1+2,ans=0;
    for(int j=1;j<=3;++j) if(j!=qj) ans+=(abc[qi][j]-'A');
    abc[qi][qj]=sum-ans+'A';
    cout<<abc[qi][qj]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}