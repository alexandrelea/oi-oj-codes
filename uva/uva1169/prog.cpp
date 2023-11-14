#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,c,x[N],y[N],w[N],sw[N],sd[N],dp[N];
void solve(){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=sd[0]=sw[0]=0;
    cin>>c>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i]>>w[i];
    for(int i=1;i<=n;++i)
        sd[i]=sd[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]),sw[i]=sw[i-1]+w[i];
    for(int i=1;i<=n;++i){
        int &ans=dp[i];
        for(int j=i-1;j>=0&&sw[i]-sw[j]<=c;--j){
            ans=min(dp[j]+x[j+1]+y[j+1]+sd[i]-sd[j+1]+x[i]+y[i],ans);
        }
    }
    cout<<dp[n]<<endl;
}
int main(){
    int T,o=0;
    cin>>T;
    while(T--){
        if(o) cout<<endl;
        solve();
        o=1;
    }
    return 0;
}