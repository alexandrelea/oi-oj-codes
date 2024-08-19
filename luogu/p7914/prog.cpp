#include <iostream>
#define int long long
using namespace std;
const int MOD=1e9+7;
int n,k,f[510][510][6]={};
char st[510];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>st[i],f[i][i-1][0]=1;
    for(int ln=1;ln<=n;ln++){
        for(int i=1,j=ln;j<=n;i++,j++){
            if(ln<=k) f[i][j][0]=f[i][j-1][0]&&(st[j]=='*'||st[j]=='?');
            if(ln>=2){
                if((st[i]=='('||st[i]=='?')&&(st[j]==')'||st[j]=='?')) f[i][j][1]=(f[i+1][j-1][0]+f[i+1][j-1][2]+f[i+1][j-1][3]+f[i+1][j-1][4])%MOD;
                for(int k=i;k<j;k++){
                    f[i][j][2]=(f[i][j][2]+f[i][k][3]*f[k+1][j][0])%MOD;
                    f[i][j][3]=(f[i][j][3]+(f[i][k][2]+f[i][k][3])*f[k+1][j][1])%MOD;
                    f[i][j][4]=(f[i][j][4]+(f[i][k][4]+f[i][k][5])*f[k+1][j][1])%MOD;
                    f[i][j][5]=(f[i][j][5]+f[i][k][4]*f[k+1][j][0])%MOD;
                }
            }
            f[i][j][3]=(f[i][j][3]+f[i][j][1])%MOD;
            f[i][j][5]=(f[i][j][5]+f[i][j][0])%MOD;
            // cout<<"f "<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<" "<<f[i][j][3]<<" "<<f[i][j][4]<<" "<<f[i][j][5]<<endl;
        }
    }
    cout<<f[1][n][3]<<endl;
    return 0;
}