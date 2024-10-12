// 洛谷 p1360 - Gold Balanced Lineup G
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll b=100019,p=1'0000'0000'0000'0000'03;
int n,m,ans=0;
ll cnt[35];
ll hf(auto *ea){
    ll ans=0;
    for(int i=2;i<=m;++i) ans*=b,ans+=(ea[i]-ea[1]),ans%=p;
    return ans;
}
map<ll,int> memo;
int main(){
    cin>>n>>m;
    memo[0]=0;
    for(int i=1;i<=n;++i){
        int S;
        cin>>S;
        for(int j=1;j<=m;++j) cnt[j]+=!!(S&(1<<(j-1)));
        // for(int j=2;j<=m;++j) cout<<cnt[j]-cnt[1]<<" ";
        // cout<<endl;
        ll hcnt=hf(cnt);
        if(memo.count(hcnt)) ans=max(ans,i-memo[hcnt]);
        else memo[hcnt]=i;
    }
    cout<<ans<<endl;
    return 0;
}