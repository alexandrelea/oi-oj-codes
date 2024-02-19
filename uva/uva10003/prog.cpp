#include <bits/stdc++.h>
using namespace std;
int l,n,a[60],dp[60][60]={};
void solve(){
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],dp[i][i+1]=0;
    a[n+1]=l,dp[0][1]=0;
    for(int l=2;l<=n+1;++l){
        for(int i=0,j=i+l;j<=n+1;++j,++i){
            for(int k=i+1;k<j;++k) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            dp[i][j]+=a[j]-a[i];
        }
    }
    cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
}
int main(){
    while(cin>>l&&l!=0) solve();
    return 0;
}