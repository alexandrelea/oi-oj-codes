// CF1986B - Matrix Stabilization
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][110];
void solve(){
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
    while(1){
        bool ok=false;
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
            int p=a[i+1][j],q=a[i-1][j],r=a[i][j+1],s=a[i][j-1],mx=max(max(p,q),max(r,s));
            if(a[i][j]>mx) a[i][j]=mx;
        }
        if(!ok) break;
    }
    for(int i=1;i<=n;++i,cout<<endl) for(int j=1;j<=m;++j) cout<<a[i][j]<<" ";
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}