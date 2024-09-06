// UVa1665 - Islands
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int NM=1000*1000+5,Q=100005;
int n,m,q,qu[Q],ans[Q],fa[NM],hi[NM];
int griid(int i,int j){
    if(i==0&&j==0) return 0;
    return (i-1)*m+j;
}
struct grid{
    int i,j,h,u;
    grid(int i=0,int j=0,int h=0,int u=0):i(i),j(j),h(h),u(u){}
}G[NM];
int find(int x){
    return fa[x]=fa[x]==x?fa[x]:find(fa[x]);
}
const int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
        cin>>hi[griid(i,j)];
        G[griid(i,j)]=grid(i,j,hi[griid(i,j)],griid(i,j));
        fa[griid(i,j)]=-1;
    }
    sort(G+1,G+n*m+1,[](grid a,grid b)->bool {
        return a.h!=b.h?a.h>b.h:(a.i!=b.i?a.i<b.i:a.j<b.j);
    });
    int ie=1,cnt=0;
    memset(ans,0,sizeof(ans));
    cin>>q;
    for(int i=1;i<=q;++i) cin>>qu[i];
    for(int _=q;_>=1&&ie<=n*m;--_){
        if(qu[_]==qu[_+1]) ans[_]=ans[_+1];
        while(G[ie].h>qu[_]&&ie<=n*m){
            int u=G[ie].u;
            if(fa[u]==-1) fa[u]=u,++cnt;
            for(int c=0;c<4;++c){
                int ii=G[ie].i+mov[c][0],jj=G[ie].j+mov[c][1],v=griid(ii,jj);
                if(1<=ii&&ii<=n&&1<=jj&&jj<=m&&hi[v]>qu[_]&&fa[v]!=-1){
                    int w=find(u);
                    v=find(v);
                    if(v!=w) fa[v]=w,--cnt;
                }
            }
            ++ie;
        }
        ans[_]=cnt;
        if(ie==n*m+1) for(int __=1;__<_;++__) ans[__]=ans[_];
    }
    for(int i=1;i<=q;++i) cout<<ans[i]<<" ";
    cout<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}