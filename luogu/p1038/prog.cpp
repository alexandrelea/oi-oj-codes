#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef __int128_t lnt;
int n,p,in[110],ou[110];
long long v;
lnt c[110],e[110];
vector<pair<int,long long>> edge[110];
int main(){
    queue<int> que;
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>v,c[i]=v,cin>>v,e[i]=v;
    for(int i=1;i<=p;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back(make_pair(v,w));
        in[v]++,ou[u]++;
    }
    for(int i=1;i<=n;i++) if(in[i]==0) que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        if(c[u]==0) continue;
        for(auto edg:edge[u]){
            int v=edg.first;
            long long w=edg.second;
            c[v]+=w*c[u],in[v]--;
            if(in[v]==0) c[v]-=e[v],c[v]=max(c[v],(lnt)0),que.push(v);
        }
    }
    bool all0=true;
    for(int i=1;i<=n;i++) if(ou[i]==0&&c[i]!=0){
        all0=false;
        break;
    }
    if(all0) cout<<"NULL"<<endl;
    else{
        for(int i=1;i<=n;i++) if(ou[i]==0&&c[i]!=0) cout<<i<<" "<<(v=c[i])<<endl;
    }
    return 0;
}