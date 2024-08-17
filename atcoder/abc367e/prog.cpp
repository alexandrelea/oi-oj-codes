// ATBC367E - Permute K times
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],x[N],f[N],c[N];
long long k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=n;++i) cin>>a[i],f[i]=i;
    while(k){
        if(k&1){
            for(int i=1;i<=n;++i) c[i]=f[x[i]];
            for(int i=1;i<=n;++i) f[i]=c[i];
        }
        for(int i=1;i<=n;++i) c[i]=x[x[i]];
        for(int i=1;i<=n;++i) x[i]=c[i];
        k>>=1;
    }
    for(int i=1;i<=n;++i) cout<<a[f[i]]<<" ";
    return 0;
}