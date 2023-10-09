#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,c[510],f[510][510]={};
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) cin>>c[i],f[i][i]=1;
    for(int i=1;i<n;i++) f[i][i+1]=(c[i]==c[i+1]?1:2);
    for(int l=3;l<=n;l++){
        for(int i=1,j=l;j<=n;i++,j++){
            if(c[i]==c[j]) f[i][j]=f[i+1][j-1];
            else for(int k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}