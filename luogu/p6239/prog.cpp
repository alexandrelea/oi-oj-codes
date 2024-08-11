#include <iostream>
using namespace std;
const int size=33,mod=1e9+7;
int main(){
    int n,m,k,f[size][size][size][(1<<9)]={};
    cin>>n>>m>>k;
    f[2][0][0][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int s=0;s<(1<<(k+1));s++){
                for(int l=0;l<=k;l++){
                    if(l!=min(i-1,k)){
                        f[i][j][l+1][s]=(f[i][j][l+1][s]+f[i][j][l][s])%mod;
                        f[i][j+1][l][s^(1<<k)^(1<<(l+k-min(i-1,k)))]=(f[i][j+1][l][s^(1<<k)^(1<<(l+k-min(i-1,k)))]+f[i][j][l][s])%mod;
                    }
                    if(l==min(i-1,k)&&(!(s&1))){
                        f[i+1][j][0][s>>1]=(f[i+1][j][0][s>>1]+f[i][j][l][s])%mod;
                    }
                }
            }
        }
    }
    cout<<f[n+1][m][0][0]<<endl;
    return 0;
}