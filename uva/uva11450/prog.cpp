// UVa11450 - Wedding shopping
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=25,M=205,inf=0x3f3f3f3f;
int m,c,k[N],p[N][N],f[N][M];
int dp(int g,int b){
    if(b<0) return -inf;
    if(g==c+1) return m-b;
    int &ans=f[g][b];
    if(ans>=0) return ans;
    for(int i=1;i<=k[g];++i) ans=max(ans,dp(g+1,b-p[g][i]));
    return ans;
}
void solve(){
    cin>>m>>c;
    for(int i=1;i<=c;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j) cin>>p[i][j];
    }
    memset(f,0xea,sizeof(f));
    if(dp(1,m)<0) cout<<"no solution"<<endl;
    else cout<<dp(1,m)<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}