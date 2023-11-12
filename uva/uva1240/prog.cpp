#include<bits/stdc++.h>
using namespace std;
int n,t[4][15],memo[1<<15][4][300];
int dp(int sol,int las,int tot){
    if(tot>=280) return 0;
    if(las!=0&&memo[sol][las][tot]!=-1) return memo[sol][las][tot];
    // for(int i=n;i>=1;i--) cout<<!!(sol&(1<<(i-1)));
    // cout<<" "<<las<<" "<<tot<<endl;
    int ans=0;
    for(int i=1;i<=3;++i) if(i!=las){
        for(int j=1;j<=n;++j) if((sol&(1<<(j-1)))==0&&tot+t[i][j]<=280){
            ans=max(ans,1+dp(sol|(1<<(j-1)),i,tot+t[i][j]));
        }
    }
    if(las==0) return ans;
    return memo[sol][las][tot]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=3;++i) for(int j=1;j<=n;++j) cin>>t[i][j];
        memset(memo,-1,sizeof(memo));
        cout<<dp(0,0,0)<<endl;
    }
    return 0;
}