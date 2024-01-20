#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,h[N],v[N],re[N];
int to,stk[N],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i]>>v[i];
    for(int i=1;i<=n;++i){
        while(to>0&&h[stk[to-1]]<=h[i]) re[i]+=v[stk[to-1]],--to;
        stk[to++]=i;
    }
    to=0;
    for(int i=n;i>=1;--i){
        while(to>0&&h[stk[to-1]]<=h[i]) re[i]+=v[stk[to-1]],--to;
        stk[to++]=i;
    }
    for(int i=1;i<=n;++i) ans=max(ans,re[i]);
    cout<<ans<<endl;
    return 0;
}