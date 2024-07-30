#include <bits/stdc++.h>
using namespace std;
int n,t;
void solve(){
    int ans=0,a;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a;
        if(i%2==1) ans=max(ans,a);
    }
    cout<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--) solve();
    return 0;
}