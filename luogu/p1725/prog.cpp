#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;
int n,l,r,a[N],f[N],ans,que[N],h,t;
int main(){
    memset(f,0xc0,sizeof(f));
    f[0]=0,ans=-INF;
    cin>>n>>l>>r;
    for(int i=0;i<=n;++i) cin>>a[i];
    for(int i=l;i<=n;++i){
        for(;f[i-l]>=f[que[t]]&&t>=h;--t);
        que[++t]=i-l;
        for(;que[h]+r<i;++h);
        f[i]=f[que[h]]+a[i];
        if(i+r>n) ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}