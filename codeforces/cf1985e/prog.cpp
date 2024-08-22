// CF1985E - Secret Box
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll x,y,z,k,ans=0;
    cin>>x>>y>>z>>k;
    for(ll u=1;u<=x;++u){
        if(k%u!=0) continue;
        for(ll v=1;v<=y;++v){
            if(k/u%v!=0) continue;
            ll w=k/u/v;
            if(w<=z){
                // cerr<<u<<" "<<v<<" "<<w<<" "<<(x-u+1)*(y-v+1)*(z-w+1);
                ans=max(ans,(x-u+1)*(y-v+1)*(z-w+1));
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}