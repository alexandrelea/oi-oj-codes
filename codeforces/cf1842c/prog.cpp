// Codeforces 1842C - Tenzing and Balls
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],f[N],g[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    f[1]=0;
    memset(g,0xc0,sizeof(g));
    for(int i=1;i<=n;++i){
        f[i]=max(f[i-1],g[a[i]]+i);
        g[a[i]]=max(g[a[i]],f[i-1]-i+1);
    }
    cout<<f[n]<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}