#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if((n+m)%2==0) cout<<"Tonya"<<endl;
        else cout<<"Burenka"<<endl;
    }
    return 0;
}