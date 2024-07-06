#include <bits/stdc++.h>
using namespace std;
const int N=2e5,inf=0x3f3f3f3f;
int n,k,a[N+10],ans=inf;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,I=n-k;I<=n;++i,++I) ans=min(ans,a[I]-a[i]);
    cout<<ans<<endl;
    return 0;
}