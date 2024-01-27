#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x,n;
    cin>>x>>n;
    // for(int g=x/2;g>=1;--g){
    //     if(x%g!=0) continue;
    //     if(x/g>=n){
    //         cout<<g<<endl;
    //         return;
    //     }
    // }
    for(int g=x/n;g>=0;--g) if(x%g==0){
        cout<<g<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}