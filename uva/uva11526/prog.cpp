#include <iostream>
#include <cmath>
#define int long long
using namespace std;
// 2*(Sum_{i=1..floor(sqrt(n))} floor(n/i)) - floor(sqrt(n))^2
int sum(int lb,int ub,int n){
    int ans=0;
    for(int i=lb;i<=ub;i++) ans+=n/i;
    return ans;
}
signed main(){
    int n,t,sn=1;
    cin>>t;
    while(t--){
        cin>>n;
        sn=floor(sqrt(n));
        cout<<2*sum(1,sn,n)-(sn*sn)<<endl;
    }
    return 0;
}