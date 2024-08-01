#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
vector<int> a,c;
map<int,int> flw;
void solve(){
    cin>>n>>m;
    a.resize(n),c.resize(n),flw.clear();
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>c[i],flw[a[i]]=c[i];
    int ans=0;
    for(auto ie:flw){
        int x=ie.first,cx=ie.second;
        ans=max(ans,min(m/x,cx)*x);
        if(flw.count(x+1)){
            int x_=x+1,cx_=flw[x+1],k1=min(m/x,cx),pred=x*k1,co;
            cx-=k1,co=m-pred;
            if(co>=x+1){
                int k2=min(co/x_,cx_);
                pred+=k2*x_;
                cx_-=k2;
                co=m-pred;
            }
            ans=max(ans,min(m/x_,cx_));
            pred+=min(min(co,cx_),k1);
            ans=max(pred,ans);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}