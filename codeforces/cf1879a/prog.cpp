#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,s[N],e[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>s[i]>>e[i];
    for(int i=2;i<=n;++i) if(s[i]>=s[1]&&e[i]>=e[1]){
        cout<<-1<<endl;
        return;
    }
    cout<<s[1]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}