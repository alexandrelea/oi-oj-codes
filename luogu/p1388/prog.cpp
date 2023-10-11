#include <iostream>
using namespace std;
int n,m,k,a[20]={},f[20][20][20]={},sum[20]={};
void mdfs(int x,int y,int z){
    if(f[x][y][z]!=-1) return;
    if(x==y&&z==0){
        f[x][y][z]=a[x];
        return;
    }
    int t;
    for(int i=0;i<=min(y-x-1,min(m,z-1));i++){
        for(int j=x;j<=y-1;j++){
            if(i<=j-x&&z-i-1<=y-(j+1)) mdfs(x,j,i),mdfs(j+1,y,z-i-1);
            else continue;
            f[x][y][z]=max(f[x][y][z],f[x][j][i]*f[j+1][y][z-i-1]);
            t=f[x][y][z];
        }
    }
    for(int i=0;i<=min(y-x,min(m,z));i++){
        for(int j=x;j<=y-1;j++){
            if(i<=j-x&&z-i<=y-(j+1)) mdfs(x,j,i),mdfs(j+1,y,z-i);
            else continue;
            f[x][y][z]=max(f[x][y][z],f[x][j][i]+f[j+1][y][z-i]);
            t=f[x][y][z];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) f[i][j][k]=-1;
    mdfs(1,n,m);
    cout<<f[1][n][m]<<endl;
    return 0;
}