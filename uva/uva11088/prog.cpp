#include <bits/stdc++.h>
using namespace std;
int n,pi[16],memo[(1<<16)];
int dp(int S){
    if(memo[S]!=-1) return memo[S];
    int &ans=memo[S];
    ans=0;
    for(int i=1;i<=n;++i) if(S&(1<<(i-1))){
        ans=max(ans,dp(S&(~(1<<(i-1)))));
        for(int j=i+1;j<=n;++j) if(S&(1<<(j-1)))
            for(int k=j+1;k<=n;++k) if(S&(1<<(k-1)))
                if(pi[i]+pi[j]+pi[k]>=20)
                    ans=max(ans,1+dp(S&(~((1<<(i-1))|(1<<(j-1))|(1<<(k-1))))));
        break;
    }
    return ans;
}
signed main(){
    int tid=0;
    while(cin>>n&&n){
        for(int i=1;i<=n;++i) cin>>pi[i];
        memset(memo,-1,sizeof(memo));
        cout<<"Case "<<(++tid)<<": "<<dp((1<<n)-1)<<endl;
    }
    return 0;
}