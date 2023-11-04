#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int SIZE=2e5+10;
int n,m,a[SIZE],b[SIZE],col[SIZE*2];
vector<int> edge[SIZE*2];
bool bfs(int x){
    queue<int> que;
    col[x]=0;
    que.push(x);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(auto v:edge[u]){
            if(col[v]==-1) col[v]=col[u]^1,que.push(v);
            else if(col[v]==col[u]) return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++) col[i]=col[i]=-1;
    for(int i=1;i<=m;i++){
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            if(!bfs(i)) return cout<<"No"<<endl,0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}