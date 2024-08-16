// LG2872 - Building Roads S
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,fa[N];
double x[N],y[N],ans;
vector<pair<double,pair<int,int>>> edge;
int fn(int u){
    return fa[u]=fa[u]==u?fa[u]:fn(fa[u]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i],fa[i]=i;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j){
        double dx=x[i]-x[j],dy=y[i]-y[j],dis=sqrt(dx*dx+dy*dy);
        edge.push_back({dis,{i,j}});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        u=fn(u),v=fn(v);
        if(u!=v) fa[u]=v,--n;
    }
    cerr<<n<<endl;
    for(auto edg:edge){
        int u=edg.second.first,v=edg.second.second;
        u=fn(u),v=fn(v);
        double w=edg.first;
        if(u!=v) --n,ans+=w,fa[u]=v;
        if(!n) break;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
