#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,dis[N],fa[N];
bool vis[N];
vector<pair<int,int>> gr[N],bftr[N];
void bfs0(){
    memset(dis,0x3f,sizeof dis);
    queue<int> que;
    que.push(n),dis[n]=0;
    while(!que.empty()){
        int u=que.front();que.pop();
        for(auto edg:gr[u]){
            int v=edg.first;
            if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,que.push(v);
        }
    }
}
void bfs1(){
    vector<int> lev;
    vector<int> ans;
    lev.push_back(1);
    cout<<dis[1]<<endl;
    for(int i=1;i<=dis[1];++i){
        int minc=0x3f3f3f3f;
        for(int u:lev) for(auto edg:gr[u]){
            int v=edg.first,c=edg.second;
            if(dis[v]==dis[u]-1&&c<minc) minc=c;
        }
        ans.push_back(minc);
        vector<int> nlev;
        for(int u:lev) for(auto edg:gr[u]){
            int v=edg.first,c=edg.second;
            if(dis[v]==dis[u]-1&&!vis[v]&&c==minc) nlev.push_back(v),vis[v]=1;
        }
        lev=nlev;
    }
    cout<<ans[0];
    for(int i=1;i<dis[1];++i) cout<<" "<<ans[i];
    cout<<endl;
}
int main(){
    while(cin>>n>>m){
        memset(dis,0,sizeof dis);
        memset(fa,0,sizeof fa);
        memset(vis,0,sizeof vis);
        for(int i=1;i<=n;++i) gr[i].clear(),bftr[i].clear();
        for(int i=1;i<=m;++i){
            int u,v,c;
            cin>>u>>v>>c;
            gr[u].push_back(make_pair(v,c));
            gr[v].push_back(make_pair(u,c));
        }
        bfs0();
        for(int i=1;i<=n;++i) sort(gr[i].begin(),gr[i].end(),[](pair<int,int> a,pair<int,int> b)->bool {return a.second<b.second;});
        bfs1();
    }
    return 0;
}