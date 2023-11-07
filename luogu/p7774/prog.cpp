#include <iostream>
using namespace std;
int n,m,a[15],b[15],f[1010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    f[0]=1;
    for(int i=1;i<=n;i++) for(int j=0;j<=1000;j++) if(j>=a[i]) f[j%360]|=f[(j-a[i])%360],f[j%360]|=f[(j+a[i])%360];
    for(int i=1;i<=m;i++) cout<<(f[b[i]]?"YES":"NO")<<endl;
    return 0;
}