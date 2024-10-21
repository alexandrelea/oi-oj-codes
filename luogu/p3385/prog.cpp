// 洛谷 p3385 - 【模板】负环
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edge> edges;
vector<int> gr[N];
int n,m,dis[N],cnt[N];
bool vis[N];
void adde(int u,int v,int w){
    edges.push_back(edge(u,v,w));
    gr[u].push_back(edges.size()-1);
}
void solve(){
    cin>>n>>m;
    edges.clear();
    for(int i=1;i<=n;++i) gr[i].clear();
    for(int i=1,u,v,w;i<=m;++i){
        cin>>u>>v>>w;
        if(w>=0) adde(u,v,w),adde(v,u,w);
        else adde(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    dis[1]=0,vis[1]=1;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int u=que.front();vis[u]=0,que.pop();
        for(int ei:gr[u]){
            int v=edges[ei].v,w=edges[ei].w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w,cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return cout<<"YES"<<endl,void();
                if(!vis[v]) vis[v]=1,que.push(v);
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}