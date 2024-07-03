#include <bits/stdc++.h>
using namespace std;
int n,aj[30][30],ans;
vector<int> gr[30],rte;
bool vis[30];
void dfs(int cur){
    if(cur==n){
        bool _=false;
        for(int ie:rte){
            if(_) cout<<" ";
            cout<<ie;
            _=true;
        }
        cout<<endl;
        ++ans;
        return;
    }
    for(int nxt:gr[cur]){
        if(vis[nxt]) continue;
        vis[nxt]=true;
        rte.push_back(nxt);
        dfs(nxt);
        vis[nxt]=false;
        rte.pop_back();
    }
}
int main(){
    int _=0;
    vis[1]=true,rte.push_back(1);
    while(cin>>n){
        int u,v;
        ans=0;
        for(int i=0;i<30;++i) gr[i].clear();
        memset(aj,0,sizeof aj);
        while(cin>>u>>v&&u!=0&&v!=0) gr[u].push_back(v),gr[v].push_back(u),aj[u][v]=aj[v][u]=1;
        for(int i=1;i<=20;++i) gr[i].push_back(i),aj[i][i]=1;
        for(int k=1;k<=20;++k) for(int i=1;i<=20;++i) for(int j=1;j<=20;++j) aj[i][j]|=aj[i][k]&&aj[k][j];
        for(int i=1;i<=20;++i) sort(gr[i].begin(),gr[i].end());
        cout<<"CASE "<<(++_)<<":"<<endl;
        if(aj[1][n]) dfs(1);
        cout<<"There are "<<ans<<" routes from the firestation to streetcorner "<<n<<"."<<endl;
    }
    return 0;
}