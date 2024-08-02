#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(){
    int n,s1,v1,s2,v2;
    cin>>n>>s1>>v1>>s2>>v2;
    if(s1>s2) swap(s1,s2),swap(v1,v2);
    ll ans=0;
    if(n/s2>=65536){
        for(ll i=0;i<=s1;++i) ans=max(ans,v2*i+(n-s2*i)/s1*v1);
        for(ll i=0;i<=s2;++i) ans=max(ans,v1*i+(n-s1*i)/s2*v2);
    }else for(ll i=0;s2*i<=n;++i) ans=max(ans,v2*i+(n-s2*i)/s1*v1);
    return ans;
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--) cout<<"Case #"<<(++__)<<": "<<solve()<<endl;
    return 0;
}