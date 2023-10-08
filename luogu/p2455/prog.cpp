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
        int p=i;
        for(int j=i;j<=n;j++) if(maxn<data[j][i]) maxn=data[p=j][i];
        if(maxn==0){
            bool all0=true;
            for(int j=1;j<=n+1;j++) if(data[i][j]!=0.0){
                all0=false;
                break;
            } 
            if(all0) for(int j=i;j<=n+1;j++) swap(data[i][j],data[n][j]);
            continue;
        }
        for(int j=1;j<=n+1;j++) swap(data[p][j],data[i][j]);
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            double co=data[j][i]/data[i][i];
            for(int k=1;k<=n+1;k++) data[j][k]-=data[i][k]*co;
        }
    }
    for(int i=1;i<=n;i++){
        if(data[i][n+1]==0.0&&data[i][i]==0.0) return cout<<0<<endl,0;
        else if(data[i][n+1]!=0.0&&data[i][i]==0.0) return cout<<-1<<endl,0;
        data[i][n+1]/=data[i][i];
    }
    for(int i=1;i<=n;i++){
        cout<<'x'<<i<<"=";
        if(data[i][n+1]==-0.0) cout<<"0.00"<<endl;
        else cout<<fixed<<setprecision(2)<<data[i][n+1]<<endl;
    }
    return 0;
}