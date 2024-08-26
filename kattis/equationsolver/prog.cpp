// KATEQUATIONSOLVER - Linear Equation Solver
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
using namespace std;
const double eps=1e-3;
int n;
double M[107][107];
bool vis[107];
void solve(){
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>M[i][j];
    for(int i=1;i<=n;++i) cin>>M[i][n+1],vis[i]=0;
    bool ok=1,inc=0;
    // Gauss-Jordan Elimination.
    for(int i=1;i<=n;++i){
        int ii=i;
        for(int j=1;j<=n;++j){
            if(!vis[j]&&fabs(M[ii][i])<fabs(M[j][i])) ii=j;
        }
        for(int j=1;j<=n+1;++j) swap(M[ii][j],M[i][j]);
        if(fabs(M[i][i])<eps){
            ok=0;
            continue;
        }
        vis[i]=1;
        // We've chosen the main unknown. In the normal case.
        double mii=M[i][i];
        for(int j=1;j<=n+1;++j) M[i][j]/=mii;
        for(int j=1;j<=n;++j){
            if(j==i) continue;
            double c=M[j][i];
            for(int k=1;k<=n+1;++k) M[j][k]-=M[i][k]*c;
        }
    }
    if(ok){
        for(int i=1;i<=n;++i) cout<<M[i][n+1]<<" ";
        cout<<endl;
    }else{
        for(int i=1;i<=n;++i) if(fabs(M[i][i])<eps&&fabs(M[i][n+1])>eps)inc=1;
        cout<<(inc?"inconsistent":"multiple")<<endl;
    }
}
int main(){
    while(cin>>n&&n) solve();
    return 0;
}