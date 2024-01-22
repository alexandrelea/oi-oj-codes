#include<bits/stdc++.h>
using namespace std;
int n,m,fa[310],ans1,ans2;
struct edge{
    int u,v,w;
}gr[8010];
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i) cin>>gr[i].u>>gr[i].v>>gr[i].w;
    sort(gr+1,gr+m+1,[](edge a,edge b)->bool {return a.w<b.w;});
    for(int i=1;i<=m;++i){
        int u=gr[i].u,v=gr[i].v,w=gr[i].w;
        u=find(u),v=find(v);
        if(u!=v) ans1++,ans2=max(ans2,w),fa[u]=v;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}