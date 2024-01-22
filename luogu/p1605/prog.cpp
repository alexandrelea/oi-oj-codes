#include <bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,ans;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool br[7][7];
void dfs(int x,int y){
    if(x==fx&&y==fy) return ++ans,void();
    for(int co=0;co<4;++co){
        int nx=x+dir[co][0],ny=y+dir[co][1];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&br[nx][ny]==0){
            br[nx][ny]=1;
            dfs(nx,ny);
            br[nx][ny]=0;
        }
    }
}
int main(){
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    while(t--){
        int bx,by;
        cin>>bx>>by;
        br[bx][by]=true;
    }
    br[sx][sy]=true,dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}