#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q,x,y,z,cnt=0;
int p[N],fa[N],dis[N];
int find(int x){
    if(fa[x]!=x){
        int t=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[t];
    }
    return fa[x];
}
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=q;++i){
        int x,y,z;
        cin>>x>>y>>z;
        int a=find(x),b=find(y);
        if(!(a==b&&dis[x]-dis[y]!=z))
            p[++cnt]=i,fa[a]=b,dis[a]=z+dis[y]-dis[x];
    }
    for(int i=1;i<=cnt;++i) cout<<p[i]<<" ";
    return 0;
}