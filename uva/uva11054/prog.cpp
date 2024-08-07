#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(cin>>n&&n){
        ll ans=0,a,las=0;
        for(int i=1;i<=n;++i) cin>>a,ans+=abs(las),las+=a;
        cout<<ans<<endl;
    }
    return 0;
}