#include <bits/stdc++.h>
using namespace std;
int n,m;
long long k,ans;
struct edge{
    int u,v;
    long long w;
    edge(int u=0,int v=0,long long w=0):u(u),v(v),w(w){}
}G[60];
int fa[10]={};
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>n>>m>>k,ans=k+1;
    for(int i=1;i<=m;++i){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        G[i]=edge(u,v,w);
    }
    for(long long S=0;S<(1<<m+1);++S){
        if(__builtin_popcount(S)==n-1){
            fa[1]=1,fa[2]=2,fa[3]=3,fa[4]=4,fa[5]=5,fa[6]=6,fa[7]=7,fa[8]=8;
            long long amo=0;
            int con=n;
            bool ok=true;
            for(long long i=1;i<=m;++i){
                if(S&(1<<i-1)){
                    int u=G[i].u,v=G[i].v;
                    long long w=G[i].w;
                    u=find(u),v=find(v);
                    if(u!=v) amo+=w,amo%=k,fa[u]=v,--con;
                    else{
                        ok=false;
                        break;
                    }
                }
            }
            if(ok&&con==1) ans=min(ans,amo);
        }
    }
    cout<<ans<<endl;
    return 0;
}