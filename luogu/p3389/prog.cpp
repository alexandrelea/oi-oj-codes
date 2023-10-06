#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    double data[110][110];
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) cin>>data[i][j];
    for(int i=1;i<=n;i++){
        double maxn=-1.0/0.0;
        int p;
        for(int j=i+1;j<=n;j++) if(maxn<data[j][j]) maxn=data[j][p=j];
        for(int j=1;j<=n+1;j++) swap(data[p][j],data[i][j]);
        if(data[i][i]==0) return cout<<"No Solution"<<endl,0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            double co=data[j][i]/data[i][i];
            for(int k=1;k<=n+1;k++) data[j][k]-=data[i][k]*co;
        }
    }
    for(int i=1;i<=n;i++) data[i][n+1]/=data[i][i];
    return 0;
}