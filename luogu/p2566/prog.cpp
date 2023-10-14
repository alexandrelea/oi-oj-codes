#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int n,m,d,stn;
char mp[15][15];
int sum[(1<<11)],vx[15],vy[15];
bool vis[15][15][1<<11];
int stp[15][15][1<<11];
void check(int lx,int ly,int nx,int ny,int &ns){
    for(int i=1;i<=d;i++) if(((lx==vx[i]&&nx<vx[i])||(lx<vx[i]&&nx==vx[i]))&&ny>vy[i]) ns^=(1<<i-1);
}
int bfs(int x,int y){
    typedef tuple<int,int,int> state;
    int ans=0;
    queue<state> que;
    que.push(state(x,y,0));
    int tr[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    memset(stp,0x3f,sizeof(stp)),stp[x][y][0]=0;
    memset(vis,0,sizeof(vis));
    while(!que.empty()){
        state nw=que.front();que.pop();
        // cout<<get<0>(nw)<<" "<<get<1>(nw)<<" "<<get<2>(nw)<<" = "<<stp[get<0>(nw)][get<1>(nw)][get<2>(nw)]<<endl;
        vis[get<0>(nw)][get<1>(nw)][get<2>(nw)]=true;
        for(int co=0;co<4;co++){
            int nx=get<0>(nw)+tr[co][0],ny=get<1>(nw)+tr[co][1],ns=get<2>(nw);
            if(nx<1||nx>n||ny<1||ny>m||('1'<=mp[nx][ny]&&mp[nx][ny]<='9')||mp[nx][ny]=='#') continue;
            if(co%2==0) check(get<0>(nw),get<1>(nw),nx,ny,ns);
            if(vis[nx][ny][ns]) continue;
            if(stp[nx][ny][ns]>stp[get<0>(nw)][get<1>(nw)][get<2>(nw)]){
                stp[nx][ny][ns]=stp[get<0>(nw)][get<1>(nw)][get<2>(nw)]+1;
                vis[nx][ny][ns]=true;
                que.push(state(nx,ny,ns));
            }
        }
    }
    for(int i=0;i<=stn;i++) ans=max(ans,sum[i]-stp[x][y][i]);
    return ans;
}
int main(){
    int ans=-0x3f3f3f3f;
    cin>>n>>m>>d;
    for(int i=1;i<=d;i++) cin>>sum[1<<i-1];
    stn=(1<<d)-1;
    for(int i=0;i<=stn;i++){
        for(int j=1;j<=d;j++) if(i&(1<<j-1)&&i!=(1<<j-1)) sum[i]+=sum[1<<j-1];
    }
    // for(int i=0;i<=stn;i++) cout<<i<<" = "<<sum[i]<<endl;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        cin>>mp[i][j];
        if('1'<=mp[i][j]&&mp[i][j]<='9') vx[mp[i][j]-'0']=i,vy[mp[i][j]-'0']=j;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j]=='0') ans=max(ans,bfs(i,j));
    cout<<ans<<endl;
    return 0;
}