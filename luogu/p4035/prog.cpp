#include <iostream>
#include <iomanip>
using namespace std;
int n;
double c[15][15];
double cof[20][20];
int main(){
    cin>>n;
    for(int i=1;i<=n+1;i++) for(int j=1;j<=n;j++) cin>>c[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cof[i][j]=c[i][j]-c[i+1][j];
            cof[i][n+1]+=c[i][j]*c[i][j]-c[i+1][j]*c[i+1][j];
        }
        cof[i][n+1]/=2;
    }
    for(int i=1;i<=n;i++){
        double maxn=-1.0/0.0;
        int p;
        for(int j=i+1;j<=n;j++) if(maxn<cof[j][j]) maxn=cof[j][p=j];
        for(int j=1;j<=n+1;j++) swap(cof[p][j],cof[i][j]);
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            double co=cof[j][i]/cof[i][i];
            for(int k=1;k<=n+1;k++) cof[j][k]-=cof[i][k]*co;
        }
    }
    for(int i=1;i<=n;i++) cof[i][n+1]/=cof[i][i],cout<<fixed<<setprecision(3)<<cof[i][n+1]<<" ";
    return 0;
}