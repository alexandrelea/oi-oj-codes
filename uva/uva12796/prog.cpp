// UVa12796 - Teletransport
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,l,s,t;
struct mat{
    int M[105][105];
    mat operator+(mat &rhs)const{
        mat ans;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ans.M[i][j]=M[i][j]+rhs.M[i][j],ans.M[i][j]%=(int)1e4;
        return ans;
    }
    mat operator*(mat &rhs)const{
        mat ans;
        for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
            ans.M[i][j]=0;
            for(int k=1;k<=n;++k) ans.M[i][j]+=M[i][k]*rhs.M[k][j],ans.M[i][j]%=(int)1e4;
        }
        return ans;
    }
    mat(int h=0){
        memset(M,0,sizeof M);
        for(int i=1;i<=n;++i) M[i][i]=h;
    }
};
void solve(){
    mat M,I(1);
    for(int i=1;i<=n;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        M.M[i][a]++,M.M[i][b]++,M.M[i][c]++,M.M[i][d]++;
    }
    for(;l;l>>=1,M=M*M){
        if(l&1) I=I*M;
    }
    cout<<I.M[s][t]<<endl;
}
int main(){
    while(cin>>n>>l>>s>>t) solve();
    return 0;
}