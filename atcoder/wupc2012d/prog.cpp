#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[110][110],f[110][110];
    cin>>n;
    for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) cin>>a[i][j];
    for(int i=n;i>=1;--i) for(int j=1;j<=i;++j) f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
    cout<<f[1][1]<<endl;
    return 0;
}