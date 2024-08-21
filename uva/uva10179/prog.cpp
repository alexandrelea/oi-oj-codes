// UVa10179 - Irreducable Basic Fractions
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n;
void solve(){
    int phi=1,k=n;
    for(int i=2;i*i<=n;++i){
        if(k%i==0){
            k/=i,phi*=(i-1);
            while(k%i==0) k/=i,phi*=i;
        }
    }
    if(k!=1) phi*=(k-1);
    // if(n==1) phi=0;
    cout<<phi<<endl;
}
int main(){
    while(cin>>n&&n) solve();
    return 0;
}