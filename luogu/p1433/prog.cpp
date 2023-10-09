#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double x[20],y[20],a[20][20],f[20][33010],ans=1.0/0.0;
    memset(f,127,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    x[0]=y[0]=0.0;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=a[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
        }
    }
    for(int i=1;i<=n;i++) f[i][1<<(i-1)]=a[0][i];
    for(int s=1;s<(1<<n);s++){
        for(int i=1;i<=n;i++){
            if((s&(1<<(i-1)))==0) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if((s&(1<<(j-1)))==0) continue;
                f[i][s]=min(f[i][s],f[j][s-(1<<(i-1))]+a[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) ans=min(ans,f[i][(1<<n)-1]);
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}