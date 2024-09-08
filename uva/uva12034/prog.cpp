// UVa 12034 - Race
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[1010][1010]={};
int C(int n,int m){
    if(c[n][m]!=-1) return c[n][m];
    if(n==0||m==0||m==n) return c[n][m]=1;
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%10056;
}
int n,f[1010]={1};
signed main(){
    memset(c,0xff,sizeof c);
    for(int i=1;i<=1000;++i) for(int j=1;j<=i;++j) f[i]+=C(i,j)*f[i-j],f[i]%=10056;
    int _,__=0;
    cin>>_;
    while(_--) cin>>n,cout<<"Case "<<(++__)<<": "<<f[n]<<endl;
    return 0;
}