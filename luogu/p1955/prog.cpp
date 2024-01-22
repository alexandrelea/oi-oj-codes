#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,fa[N*2],x[N],y[N],e[N];
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void solve(){
    map<int,int> all;
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i]>>e[i],all[x[i]]=-1,all[y[i]]=-1;
    for(auto &it:all) it.second=++cnt;
    for(int i=1;i<=n;++i) x[i]=all[x[i]],y[i]=all[y[i]];
    for(int i=1;i<=cnt;++i) fa[i]=i;
    for(int i=1;i<=n;++i){
        int u=x[i],v=y[i];
        if(e[i]==1) fa[find(u)]=find(v);
    }
    for(int i=1;i<=n;++i){
        int u=find(x[i]),v=find(y[i]);
        if(e[i]==0&&u==v) return cout<<"NO"<<endl,void();
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}