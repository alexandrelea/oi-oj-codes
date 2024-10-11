// Codeforces 1789A - Serval and Mocha's Array
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a[105],l[105];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    memset(l,0,sizeof(l));
    bool ok=0;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) if(gcd(a[i],a[j])<=2){
        ok=1;
        break;
    }
    cout<<(ok?"yes":"no")<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}