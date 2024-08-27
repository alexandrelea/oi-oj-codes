// LG3376 - 【模板】网络最大流
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
struct edge{
    int u,v,c,f;
    edge(int u=0,int v=0,int c=0,int f=0):u(u),v(v),c(c),f(f){}
};
vector<edge> edg;
vector<int> gr[210];
void nwedg(int u,int v,int c){
    edg.push_back(edge(u,v,c,0));
    gr[u].push_back((edg.end()-edg.begin())-1);
    edg.push_back(edge(v,u,0,0));
    gr[v].push_back((edg.end()-edg.begin())-1);
}
int n,m,s,t,a[210],p[210];
int edmondskarp(int s,int t){
    int ans=0;
    while(1){
        memset(a,0,sizeof a);
        queue<int> que;
        que.push(s),a[s]=inf;
        while(!que.empty()){
            int u=que.front();que.pop();
            for(int ie:gr[u]){
                edge &e=edg[ie];
                if(a[e.v]==0&&e.c>e.f){
                    p[e.v]=ie;
                    a[e.v]=min(a[u],e.c-e.f);
                    que.push(e.v);
                }
            }
            if(a[t]!=0) break;
        }
        if(a[t]==0) break;
        for(int u=t;u!=s;u=edg[p[u]].u) edg[p[u]].f+=a[t],edg[p[u]^1].f-=a[t];
        ans+=a[t];
    }
    return ans;
}
signed main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        nwedg(u,v,w);
    }
    cout<<edmondskarp(s,t)<<endl;
    return 0;
}