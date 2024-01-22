#include<bits/stdc++.h>
using namespace std;
int n,m,fa[110],ans,cnt;
struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}gr[10010];
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
        int c;
        cin>>c;
        if(i!=j) gr[++m]=edge(i,j,c);
    }
    sort(gr+1,gr+m+1,[](edge a,edge b)->bool {return a.w<b.w;});
    for(int i=1;i<=m;++i){
        int u=gr[i].u,v=gr[i].v,w=gr[i].w;
        u=find(u),v=find(v);
        if(u!=v) fa[u]=v,ans+=w;
    }
    cout<<ans<<endl;
    return 0;
}