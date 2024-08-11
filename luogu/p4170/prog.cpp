#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n=0,s[60]={},f[60][60]={-1};
    char c;
    memset(f,0x3f,sizeof f);
    while(cin>>c) s[++n]=c-'A',f[n][n]=1;
    for(int h=1;h<n;h++){
        for(int i=1,j=1+h;j<=n;i++,j++){
            if(s[i]==s[j]) f[i][j]=min(f[i][j-1],f[i+1][j]);
            else for(int k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}