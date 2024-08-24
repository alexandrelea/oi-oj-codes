// CF1986D - Mathematical Problem
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const string foc="*+.";
const int inf=0x3f3f3f3f;
int n,nu[25],dp[25][25][2],dep=0;
int f(int p,int q,bool r2l){
    if(q<p||(r2l&&q==p)) return inf;
    if(r2l&&q==p+1) return nu[p]*10+nu[q];
    if(p==q) return nu[p];
    int &ans=dp[p][q][r2l];
    if(ans>=0) return ans;
    ans=inf;
    for(int i=p;i<q;++i){
        if(r2l){
            bool lc2=(i-p+1)>=2,rc2=(q-i)>=2;
            if(lc2&&rc2){
                ans=min(ans,f(p,i,0)+f(i+1,q,1));
                ans=min(ans,f(p,i,0)*f(i+1,q,1));
                ans=min(ans,f(p,i,1)+f(i+1,q,0));
                ans=min(ans,f(p,i,1)*f(i+1,q,0));
            }else if(lc2){
                ans=min(ans,f(p,i,1)+f(i+1,q,0));
                ans=min(ans,f(p,i,1)*f(i+1,q,0));
            }else if(rc2){
                ans=min(ans,f(p,i,0)+f(i+1,q,1));
                ans=min(ans,f(p,i,0)*f(i+1,q,1));
            }
        }else{
            ans=min(ans,f(p,i,0)+f(i+1,q,0));
            ans=min(ans,f(p,i,0)*f(i+1,q,0));
        }
    }
    // cerr<<"f "<<p<<" "<<q<<" "<<r2l<<" = "<<ans<<endl;
    return ans;
}
void solve(){
    memset(dp,0xff,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;++i){
        char ch;
        cin>>ch;
        nu[i]=ch-'0';
    }
    // cerr<<endl;
    cout<<f(1,n,1)<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}