// HDU1159 - Common Subsequence
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int n,m,f[1005][1005];
string a,b;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>a>>b){
        n=a.size(),m=b.size();
        a=" "+a,b=" "+b;
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
        cout<<f[n][m]<<endl;
        memset(f,0,sizeof(f));
    }
    return 0;
}