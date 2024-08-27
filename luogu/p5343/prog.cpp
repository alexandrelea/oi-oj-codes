// LG5343 - 【XR-1】分块
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1'0000'0000'7;
int n,p,q,m,e,Q[110][110],I[110][110],T[110][110],f[110];
set<int> ss;
void setinters(){
    set<int> pr,nf;
    cin>>p;
    for(int i=1,x;i<=p;++i) cin>>x,pr.insert(x);
    cin>>q;
    for(int i=1,x;i<=q;++i) cin>>x,nf.insert(x);
    set_intersection(pr.begin(),pr.end(),nf.begin(),nf.end(),inserter(ss,ss.begin()));
    for(int ie:ss) Q[1][ie]=1,e=max(e,ie);
    for(int i=1;i<e;++i) Q[i+1][i]=1,I[i][i]=1;
    I[e][e]=1;
}
void qeqmq(){
    for(int i=1;i<=e;++i) for(int j=1;j<=e;++j){
        T[i][j]=0;
        for(int k=1;k<=e;++k) T[i][j]+=Q[i][k]*Q[k][j],T[i][j]%=M;
    }
    for(int i=1;i<=e;++i) for(int j=1;j<=e;++j) Q[i][j]=T[i][j];
}
void ieimq(){
    for(int i=1;i<=e;++i) for(int j=1;j<=e;++j){
        T[i][j]=0;
        for(int k=1;k<=e;++k) T[i][j]+=I[i][k]*Q[k][j],T[i][j]%=M;
    }
    for(int i=1;i<=e;++i) for(int j=1;j<=e;++j) I[i][j]=T[i][j];
}
void debq(){
    // cout<<"Q"<<endl;
    // for(int i=1;i<=e;++i,cout<<endl) for(int j=1;j<=e;++j) cout<<Q[i][j]<<" ";
    // cout<<endl;
}
void debi(){
    // cout<<"I"<<endl;
    // for(int i=1;i<=e;++i,cout<<endl) for(int j=1;j<=e;++j) cout<<I[i][j]<<" ";
    // cout<<endl;
}
signed main(){
    cin>>n;
    setinters();
    f[0]=1;
    for(int i=1;i<=e;++i) for(int je:ss) f[i]+=f[i-je],f[i]%=M;
    n=n-e+1;
    debq();
    for(;n;n>>=1,qeqmq(),debq(),debi()) if(n&1) ieimq();
    int ans=0;
    for(int i=1;i<=e;++i) ans+=I[1][i]*f[i-1],ans%=M;
    cout<<ans<<endl;
    return 0;
}