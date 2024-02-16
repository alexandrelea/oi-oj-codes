#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N];
void solve(){
    int sma=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],sma+=a[i];
    sma/=n;
    for(int i=1;i<=n;++i){
        if(a[i]<sma) a[i]+=cnt,cnt=0;
        if(a[i]>sma) cnt+=(a[i]-sma),a[i]=sma;
        if(a[i]<sma){
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;
}
int main(){
    cin>>t;
    while(t--) solve();
    return 0;
}