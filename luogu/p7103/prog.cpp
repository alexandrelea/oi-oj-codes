#include <iostream>
#include <vector>
using namespace std;
const int SIZE=5e6+10;
int n,m,f[SIZE],dep[SIZE],mx0[SIZE],mx1[SIZE],ans[SIZE],dept;
vector<int> edge[SIZE];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    dept=max(dept,dep[u]);
    for(auto v:edge[u]){
        dfs(v,u);
        f[u]=max(f[u],dep[v]);
        if(f[v]>f[mx0[u]]) mx1[u]=mx0[u],mx0[u]=v;
        else mx1[u]=v;
    }
}
int dfs2(int u,int nw){
    if(f[mx1[u]]>nw) return u;
    else if(f[mx0[u]]==0||dep[u]==nw) return u;
    else return dfs2(mx0[u],nw);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        edge[u].push_back(i);
    }
    ans[0]=1;
    dfs(1,0);
    for(int i=1;i<=dept;i++) ans[i]=dfs2(ans[i-1],i);
    while(m--){
        int q;
        cin>>q;
        cout<<ans[q]<<endl;
    }
    return 0;
}
