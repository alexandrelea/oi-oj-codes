#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,c[5010],f[5010][5010],m=0,x,las=-1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x!=las) c[++m]=x,f[m][m]=0;
        las=x;
    }
    for(int l=2;l<=m;l++){
        for(int i=1,j=l;j<=m;i++,j++){
            if(c[i]==c[j]) f[i][j]=f[i+1][j-1]+1;
            else f[i][j]=min(f[i+1][j],f[i][j-1])+1;
        }
    }
    cout<<f[1][m]<<endl;
    return 0;
}