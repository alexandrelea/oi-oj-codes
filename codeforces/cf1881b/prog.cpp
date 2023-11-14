#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a[4],g;
        cin>>a[1]>>a[2]>>a[3];
        g=__gcd(a[1],__gcd(a[2],a[3]));
        cout<<((a[1]/g)+(a[2]/g)+(a[3]/g)<=6?"Yes":"No")<<endl;
    }
    return 0;
}