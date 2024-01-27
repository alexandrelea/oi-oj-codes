#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        for(char j='a';j<'a'+k;++j) cout<<j;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}