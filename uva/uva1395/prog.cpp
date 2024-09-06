// UVa 1395 - Slim Span
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=105;
struct edg{
    int u,v,w;
    edg(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edg> edgs;
vector<int> gr[N];
void nwedg(int u,int v,int w){
    edgs.push_back(edg(u,v,w));
    gr[u].push_back(edgs.end()-edgs.begin()-1);
}
int n,m,fa[N];
int fin(int x){
    return fa[x]=fa[x]==x?fa[x]:fin(fa[x]);
}
int MST(int l){
    int subt=n;
    for(int i=1;i<=n;++i) fa[i]=i;
    int minw=0x3f3f3f3f,maxw=0;
    for(int i=l;i<m;++i){
        int u=edgs[i].u,v=edgs[i].v,w=edgs[i].w;
        u=fin(u),v=fin(v);
        if(u!=v) minw=min(minw,w),maxw=max(maxw,w),fa[u]=v,--subt;
    }
    return subt==1?maxw-minw:-1;
}
void solve(){
    for(int i=1;i<=n;++i) gr[i].clear();
    edgs.clear();
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        nwedg(a,b,c);
    }
    sort(edgs.begin(),edgs.end(),[](edg a,edg b)->bool {return a.w<b.w;});
    int ans=0x3f3f3f3f;
    bool ok=0;
    for(int i=1;i<=m&&ans>=0;++i){
        int c=MST(i-1);
        if(c!=-1) ok=1,ans=min(ans,c);
    }
    cout<<(ok?ans:-1)<<endl;
}
int main(){
    while(cin>>n>>m&&(n||m)) solve();
    return 0;
}