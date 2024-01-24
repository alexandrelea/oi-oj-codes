#include <bits/stdc++.h>
using namespace std;
int n,m,t[2510],f[2510];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>t[i];
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=2;i<=n;++i) t[i]+=t[i-1];
    for(int i=1;i<=n;++i) t[i]+=2*m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            f[i]=min(f[i],f[i-j]+t[j]);
        }
    }
    cout<<f[n]-m<<endl;
    return 0;
}