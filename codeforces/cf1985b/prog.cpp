// CF1985B - Maximum Multiple Sum
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0,h;
    cin>>n;
    for(int x=2;x<=n;++x){
        int sum=0;
        for(int k=1;k*x<=n;++k) sum+=k*x;
        if(ans<sum) ans=sum,h=x;
    }
    cout<<h<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}