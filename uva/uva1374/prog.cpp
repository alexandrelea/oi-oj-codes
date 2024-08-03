#include <bits/stdc++.h>
using namespace std;
int n,ans,stat[17];
bool vis[9005];
bool dfs(int dep,int lim){
    int mS=0,ex;
    if(stat[dep]==n) return ans=dep,1;
    if(dep==lim) return 0;
    for(int i=0;i<=dep;++i) mS=max(mS,stat[i]);
    if((mS<<(lim-dep))<n) return 0;
    for(int i=dep;i>=0;--i){
        int ex=stat[dep]+stat[i];
        if(!vis[ex]){
            vis[ex]=1,stat[dep+1]=ex;
            if(dfs(dep+1,lim)) return 1;
            vis[ex]=0;
        }
        ex=abs(stat[dep]-stat[i]);
        if(!vis[ex]){
            vis[ex]=1,stat[dep+1]=ex;
            if(dfs(dep+1,lim)) return 1;
            vis[ex]=0;
        }
    }
    return 0;
}
int main(){
    stat[0]=1;
    while(cin>>n&&n){
        memset(vis,0,sizeof vis);
        for(int lim=1;lim<=13;++lim) if(dfs(0,lim)) break;
        cout<<ans<<endl;
    }
    return 0;
}