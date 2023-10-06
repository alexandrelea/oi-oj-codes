#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,m[610],f[610][610]={},sum[610]={};
    memset(f,0x3f,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>m[i],f[i][i]=0,sum[i]=sum[i-1]+m[i];
    for(int l=2;l<=n;l++){
        for(int i=1,j=i+l-1;j<=n;i++,j++){
            for(int k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}