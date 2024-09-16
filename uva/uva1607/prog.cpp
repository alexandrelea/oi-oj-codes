// UVa 1607 - Gates
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=200000+5;
int n,m,cr[N*2];
bool eo[N];
bool get(int lbo){
    for(int i=1;i<=m;++i){
        int u=cr[2*i-1],v=cr[2*i];
        if(u<0) u=-u,u=u>=lbo;
        else u=eo[u];
        if(v<0) v=-v,v=v>=lbo;
        else v=eo[v];
        eo[i]=!(u&&v);
    }
    return eo[m];
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m*2;++i) cin>>cr[i];
    bool a0=get(n+1),a1=get(1);
    if(a0==a1){
        for(int i=1;i<=n;++i) cout<<'0';
        cout<<endl;
    }else{
        int L=1,R=n+1;
        while(L<R-1){
            int M=L+((R-L)>>1);
            bool aM=get(M);
            if(aM==a0) R=M;
            else L=M;
        }
        for(int i=1;i<L;++i) cout<<'0';
        cout<<'x';
        for(int i=L+1;i<=n;++i) cout<<'1';
        cout<<endl;
    }
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}