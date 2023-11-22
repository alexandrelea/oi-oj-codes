#include <bits/stdc++.h>
using namespace std;
const int N=150010;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,w[N];
long long ww[N];
int main(){
    int T;
    cin>>T;
    while(T--){
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;++i) cin>>w[i],ww[i]=w[i]+ww[i-1];
        for(int i=1;i*i<=n;++i){
            if(n%i!=0) continue;
            long long mx=-INF,mn=INF;
            for(int j=i;j<=n;j+=i)
                mn=min(mn,ww[j]-ww[j-i]),mx=max(mx,ww[j]-ww[j-i]);
            ans=max(ans,mx-mn);
            int k=n/i;
            mx=-INF,mn=INF;
            for(int j=k;j<=n;j+=k)
                mn=min(mn,ww[j]-ww[j-k]),mx=max(mx,ww[j]-ww[j-k]);
            ans=max(ans,mx-mn);
        }
        cout<<ans<<endl;
    }
    return 0;
}