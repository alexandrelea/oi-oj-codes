#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,lb=-1,rb=1e9+10;
    vector<int> neqs;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a,x;
        cin>>a>>x;
        if(a==1) lb=max(lb,x);
        else if(a==2) rb=min(rb,x);
        else neqs.push_back(x);
    }
    int ans=rb-lb+1;
    if(rb<lb) return cout<<0<<endl,void();
    for(int it:neqs){
        if(lb<=it&&it<=rb) --ans,ans=max(ans,0);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}