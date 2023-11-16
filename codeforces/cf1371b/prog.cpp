#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long n,r,ans=0;
        cin>>n>>r;
        if(n<=r) ans+=(n-1)*n/2,ans+=1;
        else ans+=(r+1)*r/2;
        cout<<ans<<endl;
    }
    return 0;
}