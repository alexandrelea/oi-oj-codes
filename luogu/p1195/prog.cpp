// LG1195 - 口袋的天空
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k,fa[N],ans;
vector<pair<int,int>> gr[N];
vector<pair<int,pair<int,int>>> edg;
int find(int x){
    return fa[x]=fa[x]==x?fa[x]:find(fa[x]);
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({w,{u,v}});
    }
    sort(edg.begin(),edg.end());
    k=n-k;
    for(int i=0;i<m&&k;++i){
        int u=edg[i].second.first,v=edg[i].second.second,w=edg[i].first;
        u=find(u),v=find(v);
        if(u!=v) --k,ans+=w,fa[u]=v;
        cerr<<k<<" "<<ans<<endl;
    }
    if(!k) cout<<ans<<endl;
    else cout<<"No Answer"<<endl;
    return 0;
}
