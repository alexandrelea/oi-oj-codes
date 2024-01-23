#include <bits/stdc++.h>
using namespace std;
int t,n,m,p[110][1010],dp[10010];
int main(){
    cin>>t>>n>>m;
    for(int i=1;i<=t;++i) for(int j=1;j<=n;++j) cin>>p[j][i];
    for(int k=1;k<t;++k){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i){
            for(int j=p[i][k];j<=m;++j){
                dp[j]=max(dp[j],dp[j-p[i][k]]+p[i][k+1]-p[i][k]);
            }
        }
        m+=dp[m];
    }
    cout<<m<<endl;
    return 0;
}