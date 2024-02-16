#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(k==4*n-2) cout<<2*n<<endl;
        else cout<<(k+1)/2<<endl;
    }
    return 0;
}