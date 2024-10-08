// Codeforces 2001A - Make All Equal
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,a,mx=0;
    map<int,int> cnt;
    cnt.clear();
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a;
        cnt[a]++;
        mx=max(cnt[a],mx);
    }
    cout<<n-mx<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}