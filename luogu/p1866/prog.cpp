#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
int n;
ll m[55],ans=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>m[i];
    sort(m+1,m+n+1);
    for(int i=1;i<=n;++i) ans=ans*(m[i]-i+1)%M;
    cout<<ans<<endl;
    return 0;
}