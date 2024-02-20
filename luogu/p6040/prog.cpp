#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,k,d,x,tp,a[N],se,f[N],q[N],l,r;
inline int rnd(){
    static const int mod=1e9;
    return se=(1ll*se*0x66ccff%mod+20120712)%mod;
}
signed main(){
    cin>>n>>k>>d>>x>>tp;
    if(tp==0) for(int i=1;i<=n;++i) cin>>a[i];
    else{
        cin>>se;
        for(int i=1;i<=n;++i) a[i]=rnd();
    }
    f[1]=a[1],q[r]=1;
    for(int i=2;i<=n;++i){
        while(l<=r&&i-q[l]>x) ++l;
        f[i]=f[q[l]]+k+d*(i-q[l]-1)+a[i];
        while(l<=r&&f[q[r]]-q[r]*d>=f[i]-i*d) --r;
        q[++r]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}