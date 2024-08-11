// UVa10130 - SuperSale
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
int n;
ll w[N],c[N],f[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>c[i]>>w[i];
    int g,m;
    ll ans=0;
    cin>>g;
    while(g--){
        cin>>m;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;++i) for(int j=m;j>=w[i];--j)
            f[j]=max(f[j],f[j-w[i]]+c[i]);
        ans+=f[m];
    }
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}