#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,x,y,a[N];
map<pair<int,int>,int> cnt;
void solve(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;++i) cin>>a[i];
    cnt.clear();
    int ans=0;
    for(int i=1;i<=n;++i){
        int e=a[i];
        int xx=e%x,yy=e%y;
        ans+=cnt[{(x-xx)%x,yy}];
        cnt[{xx,yy}]++;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}