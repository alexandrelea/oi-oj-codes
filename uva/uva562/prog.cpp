// UVa562 - Dividing coins
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],f[50005];
void solve(){
    cin>>n,m=0;
    for(int i=1;i<=n;++i) cin>>a[i],m+=a[i];
    memset(f,0,sizeof f),f[0]=1;
    for(int i=1;i<=n;++i) for(int j=m;j>=a[i];--j)
        f[j]=max(f[j],f[j-a[i]]);
    int ans=0x3f3f3f3f;
    for(int j=0;j<=m;++j) if(f[j]) ans=min(ans,abs(m-j*2));
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}