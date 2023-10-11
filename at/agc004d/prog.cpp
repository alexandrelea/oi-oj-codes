#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int SIZE=1e5+10;
int n,k,ans=0,a[SIZE];
vector<int> edge[SIZE];
int dfs(int u,int dep){
    int ret=dep;
    for(auto v:edge[u]) ret=max(ret,dfs(v,dep+1));
    if(a[u]!=1&&ret-dep==k-1) return ans++,0;
    else return ret;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]!=1) a[1]=1,ans=1;
    for(int i=2;i<=n;i++) edge[a[i]].push_back(i);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}