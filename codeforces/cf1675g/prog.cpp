#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,b[N],w[N],c[N],ans;
vector<int> tr[N];
void dp(int u,int fa){
    if(c[u]) ++b[u];
    else ++w[u];
    for(int v:tr[u]){
        if(v==fa) continue;
        dp(v,u);
        b[u]+=b[v],w[u]+=w[v];
    }
}
void solve(){
    cin>>n,ans=0;
    for(int i=1;i<=n;++i) tr[i].clear(),b[i]=0,w[i]=0;
    for(int i=2;i<=n;++i){
        int x;
        cin>>x;
        tr[x].emplace_back(i);
        tr[i].emplace_back(x);
    }
    for(int i=1;i<=n;++i){
        char ch;
        cin>>ch;
        if(ch=='B') c[i]=1;
        else c[i]=0;
    }
    dp(1,0);
    for(int i=1;i<=n;++i) ans+=(b[i]==w[i]);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}