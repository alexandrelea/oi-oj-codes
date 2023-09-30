#include <iostream>
#define int long long
using namespace std;
const int SIZE=1e7+10,MOD=1e9+7;
signed main(){
    int t,n,q[SIZE];
    for(int i=1;i<=1e7;i++) q[i]=1;
    for(int i=2;i<=1e7;i++){
        q[i]=(q[i]+i)%MOD;
        for(int j=2;j*i<=1e7;j++) q[j*i]=(q[j*i]*q[i])%MOD;
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<q[n]<<endl;
    }
    return 0;
}