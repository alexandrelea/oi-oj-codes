#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string st,vt;
    int n,f[1010][1010]={};
    cin>>st;
    vt=st,n=st.length();
    reverse(vt.begin(),vt.end());
    vt=" "+vt,st=" "+st;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(st[i]==vt[j]) f[i][j]=f[i-1][j-1]+1;
        else f[i][j]=max(f[i-1][j],f[i][j-1]);
    }
    cout<<n-f[n][n]<<endl;
    return 0;
}