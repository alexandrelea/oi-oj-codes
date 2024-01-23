#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10,mod=1e8;
int n,f,r[N],dp[N][N];
int main(){
    cin>>n>>f;
    for(int i=1;i<=n;++i){
        cin>>r[i],r[i]%=f;
        dp[i][r[i]]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<f;++j){
            dp[i][j]=((dp[i][j]+dp[i-1][j])%mod+dp[i-1][(j-r[i]+f)%f])%mod;
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}