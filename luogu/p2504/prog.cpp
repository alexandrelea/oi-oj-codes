#include<bits/stdc++.h>
using namespace std;
int m,n,o,ans,fa[1010];
double d[510],x[1010],y[1010],dr=0;
struct eg{
    int u,v;
    double w;
    eg(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}gr[1000010];
double dist(double x,double y){
    return sqrt(x*x+y*y);
}
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>m;
    for(int i=1;i<=m;++i) cin>>d[i];
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i],fa[i]=i;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) gr[++o]=eg(i,j,dist(x[i]-x[j],y[i]-y[j]));
    sort(gr+1,gr+o+1,[](eg a,eg b)->bool {return a.w<b.w;});
    for(int i=2;i<=o;++i){
        int u=gr[i].u,v=gr[i].v;
        double w=gr[i].w;
        u=find(u),v=find(v);
        if(u!=v) fa[u]=v,dr=max(dr,w);
    }
    for(int i=1;i<=m;++i) if(d[i]>=dr) ++ans;
    cout<<ans<<endl;
    return 0;
}