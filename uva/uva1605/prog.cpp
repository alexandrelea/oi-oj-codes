#include <bits/stdc++.h>
using namespace std;
const char *ah="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main(){
    int n;
    while(cin>>n){
        cout<<2<<" "<<n<<" "<<n<<endl;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) cout<<ah[j-1];
            cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) cout<<ah[i-1];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}