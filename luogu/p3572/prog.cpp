#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,h[N],t,k,f[N],q[N*2],l,r;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i];
    cin>>t;
    while(t--){
        memset(f,0x3f,sizeof(f));
        memset(q,0,sizeof(q)),l=r=0;
        f[1]=0,q[r]=1;
        cin>>k;
        for(int i=2;i<=n;++i){
            while(r>=l&&i-q[l]>k) ++l;
            f[i]=f[q[l]]+(h[q[l]]<=h[i]);
            while(r>=l&&(f[q[r]]>f[i]||f[q[r]]==f[i]&&h[q[r]]<=h[i])) --r;
            q[++r]=i;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}