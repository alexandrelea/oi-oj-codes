// 洛谷 - P1941 [NOIP2014 提高组] 飞扬的小鸟
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,inf=0x3f3f3f3f;
int n,m,k,f[2][N],u[N],d[N],l[N],h[N],ans,tot,g[N];
int& dp(int i,int j){
    return f[i%2][j];
}
void dmem(int i){
    memset(f[i%2],0x3f,sizeof(f[i%2]));
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>u[i]>>d[i],l[i]=0,h[i]=m+1;
    for(int i=1;i<=k;++i){
        int p,ll,hh;
        cin>>p>>ll>>hh;
        l[p]=ll,h[p]=hh,g[p]=1;
    }
    for(int i=1;i<=n;++i){
        dmem(i);
        for(int j=u[i]+1;j<=u[i]+m;++j) dp(i,j)=1+min(dp(i-1,j-u[i]),dp(i,j-u[i]));
        for(int j=m+1;j<=u[i]+m;++j) dp(i,m)=min(dp(i,m),dp(i,j));
        for(int j=1;j<=m-d[i];++j) dp(i,j)=min(dp(i,j),dp(i-1,j+d[i]));
        for(int j=1;j<=l[i];++j) dp(i,j)=inf;
        for(int j=h[i];j<=m;++j) dp(i,j)=inf;
        ans=inf;
        for(int j=1;j<=m;++j) ans=min(ans,dp(i,j));
        if(ans==inf){
            cout<<0<<endl<<tot<<endl;
            return 0;
        }else tot+=g[i];
    }
    cout<<1<<endl<<ans<<endl;
    return 0;
}