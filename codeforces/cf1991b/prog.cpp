#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
void solve(){
    bool ok=true;
    cin>>n,a[1]=0;
    for(int i=1;i<n;++i) cin>>b[i],a[i+1]=0;
    for(int i=1;i<n;++i) a[i]|=b[i],a[i+1]|=b[i];
    for(int i=1;i<n;++i) if(b[i]!=(a[i]&a[i+1])){
        ok=false;
        break;
    }
    if(!ok) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}