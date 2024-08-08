#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
ll n,p,invp[N];
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0),cin.tie(0);
    cin>>n>>p;
    invp[1]=1;
    for(int i=2;i<=n;++i) invp[i]=(p-p/i)*invp[p%i]%p;
    for(int i=1;i<=n;++i) cout<<invp[i]<<"\n";
    return 0;
}