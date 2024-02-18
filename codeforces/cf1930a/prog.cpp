#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve(){
    int sum=0;
    cin>>n;
    for(int i=1;i<=2*n;++i) cin>>a[i];
    sort(a+1,a+2*n+1);
    for(int i=1;i<=n;++i) sum+=a[i*2-1];
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}