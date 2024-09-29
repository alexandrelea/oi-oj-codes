// UVa 11686 - Pick up sticks
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,in[N];
vector<int> to[N];
int main(){
    while(cin>>n>>m&&(n||m)){
        for(int i=1;i<=n;++i) in[i]=0,to[i].clear();
        for(int i=1;i<=m;++i){
            int u,v;
            cin>>u>>v;
            to[u].push_back(v),in[v]++;
        }
        vector<int> ans;
        queue<int> que;
        for(int i=1;i<=n;++i) if(in[i]==0) que.push(i);
        while(!que.empty()){
            int u=que.front();que.pop();
            ans.push_back(u);
            for(int v:to[u]){
                --in[v];
                if(in[v]==0) que.push(v);
            }
        }
        if(ans.size()==n) for(int ie:ans) cout<<ie<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}