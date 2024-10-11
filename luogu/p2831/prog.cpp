// 洛谷 - P2831 [NOIP2016 提高组] 愤怒的小鸟
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,vis[23][23],memo[1<<19],k;
double x[23],y[23],a[23][23],b[23][23];
void solveq(double x1,double y1,double x2,double y2,double &a,double &b){
    if(x1==0||x2==0||x1==x2) a=1,b=0;
    else{
        a=(x2*y1-x1*y2)/(x1*x2*(x1-x2));
        b=(y2*x1*x1-y1*x2*x2)/(x1*x2*(x1-x2));
    }
}
double fn(double x,double a,double b){
    return a*x*x+b*x;
}
int ea(int x){
    int cnt=0;
    while(x) ++cnt,x>>=1;
    return cnt;
}
int dp(int stat){
    if(memo[stat]!=inf) return memo[stat];
    int &ans=memo[stat],lb=stat&-stat,pos=ea(lb);
    ans=min(ans,dp(stat^lb)+1);
    for(int i=pos+1;i<=n;++i) ans=min(ans,1+dp(stat&(~vis[pos][i])));
    return ans;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j){
        solveq(x[i],y[i],x[j],y[j],a[i][j],b[i][j]);
        if(a[i][j]>0) continue;
        for(int k=1;k<=n;++k) if(fabs(fn(x[k],a[i][j],b[i][j])-y[k])<=1e-8) vis[i][j]|=1<<(k-1);
        // cerr<<"fun "<<a[i][j]<<" "<<b[i][j]<<" vis "<<i<<" "<<j<<" "<<vis[i][j]<<endl;
    }
    memset(memo,0x3f,sizeof(memo)),memo[0]=0;
    cout<<dp((1<<n)-1)<<endl;
    // cerr<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}