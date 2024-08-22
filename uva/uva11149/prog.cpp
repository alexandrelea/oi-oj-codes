// UVa11149 - Power of Matrix
// Code bu Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
struct phx{
    int M[103][103];
    phx(int k=0){
        memset(M,0,sizeof M);
        for(int i=1;i<=n;++i) M[i][i]=k;
    }
    phx operator+(const phx &rhs)const{
        phx ans;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ans.M[i][j]=M[i][j]+rhs.M[i][j],ans.M[i][j]%=10;
        return ans;
    }
    phx operator*(const phx &rhs)const{
        phx ans;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
            ans.M[i][j]=0;
            for(int k=1;k<=n;++k) ans.M[i][j]+=M[i][k]*rhs.M[k][j];
            ans.M[i][j]%=10;
        }
        return ans;
    }
}A,C[3][3],I[3][3],R[3][3];
void mul(phx C[][3],phx A[][3],phx B[][3]){
    phx D[3][3];
    for(int i=1;i<=2;++i) for(int j=1;j<=2;++j){
        D[i][j]=0;
        for(int k=1;k<=2;++k) D[i][j]=D[i][j]+A[i][k]*B[k][j];
    }
    for(int i=1;i<=2;++i) for(int j=1;j<=2;++j) C[i][j]=D[i][j];
}
void solve(){
    A=0;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>A.M[i][j];
    for(int i=1;i<=2;++i) for(int j=1;j<=2;++j) C[i][j]=I[i][j]=0;
    C[1][1]=C[2][1]=A,I[1][1]=I[2][2]=C[2][2]=1;
    for(;k;k>>=1,mul(C,C,C)){
        if(k&1) mul(I,C,I);
    }
    for(int i=1;i<=n;++i,cout<<endl){
        cout<<I[2][1].M[i][1];
        for(int j=2;j<=n;++j) cout<<" "<<I[2][1].M[i][j];
    }
}
signed main(){
    bool _=0;
    while(cin>>n>>k&&(n||k)){
        if(_) cout<<endl;
        solve();
        _=1;
    }
    return 0;
}