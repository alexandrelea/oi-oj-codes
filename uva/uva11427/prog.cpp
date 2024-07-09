#include <bits/stdc++.h>
using namespace std;
char eat;
int n,a,b;
double d[110][110],p;
int solve(){
    cin>>a>>eat>>b>>n;
    p=(double)a/b;
    memset(d,0,sizeof d);
    d[0][0]=1,d[0][1]=0;
    for(int i=1;i<=n;++i) for(int j=0;j*b<=a*i;++j){
        d[i][j]=d[i-1][j]*(1-p);
        if(j) d[i][j]+=d[i-1][j-1]*p;
    }
    double Q=0.0;
    for(int j=0;j*b<=a*n;++j) Q+=d[n][j];
    return 1/Q;
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--) cout<<"Case #"<<(++__)<<": "<<solve()<<endl;;
    return 0;
}