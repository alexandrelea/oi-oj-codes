// UVa580 - Critical Mass
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
long long f[35],n;
int main(){
    f[3]=1;
    f[4]=3;
    for(int i=5;i<=30;++i) f[i]=f[i-1]*2+(1<<(i-4))-f[i-4];
    while(cin>>n&&n!=0) cout<<f[n]<<endl;
    return 0;
}