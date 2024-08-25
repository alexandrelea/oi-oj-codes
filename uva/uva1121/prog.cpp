// UVa1121 - Subsequence
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,S,a[100005],aa[100005];
void solve(){
    int ans=n+1,i=1;
    for(int i=1;i<=n;++i) cin>>a[i],aa[i]=aa[i-1]+a[i];
    for(int j=1;j<=n;++j){
        if(aa[i-1]>aa[j]-S) continue;
        while(aa[i]<=aa[j]-S) ++i;
        ans=min(ans,j-i+1);
    }
    cout<<(ans==n+1?0:ans)<<endl;
}
int main(){
    while(cin>>n>>S) solve();
    return 0;
}