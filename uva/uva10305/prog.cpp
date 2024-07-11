#include <bits/stdc++.h>
using namespace std;
int n,m,in[110];
vector<int> gr[110];
void solve(){
    for(int i=1;i<=n;++i) gr[i].clear(),in[i]=0;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        ++in[v];
    }
    queue<int> que;
    for(int i=1;i<=n;++i) if(in[i]==0) que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        cout<<u<<" ";
        for(int v:gr[u]){
            --in[v];
            if(in[v]==0) que.push(v);
        }
    }
    cout<<endl;
}
int main(){
    while(cin>>n>>m&&(n||m)) solve();
    return 0;
}