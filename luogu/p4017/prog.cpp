#include <bits/stdc++.h>
using namespace std;
int n,m,in[5010],f[5010],out[5010],ans;
vector<int> gr[5010];
queue<int> que;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        in[v]++,out[u]++;
    }
    for(int i=1;i<=n;++i) if(in[i]==0) que.push(i),f[i]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int v:gr[u]){
            f[v]+=f[u];
            f[v]%=80112002;
            in[v]--;
            if(in[v]==0) que.push(v);
        }
    }
    for(int i=1;i<=n;++i) if(out[i]==0) ans+=f[i],ans%=80112002;
    cout<<ans<<endl;
    return 0;
}