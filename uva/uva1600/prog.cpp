#include <bits/stdc++.h>
using namespace std;
const int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,k;
bool cae[25][25],vis[25][25];
struct qele{
    int x,y;
    int cone,depa;
    qele(int x=0,int y=0,int cone=0,int depa=0):x(x),y(y),cone(cone),depa(depa){}
};
int solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>cae[i][j],vis[i][j]=0;
    queue<qele> que;
    que.push(qele(1,1,0,0));
    while(!que.empty()){
        int cx=que.front().x,cy=que.front().y,con=que.front().cone,st=que.front().depa;que.pop();
        if(cx==n&&cy==m) return st;
        vis[cx][cy]=1;
        for(int h=0;h<4;++h){
            int nx=cx+mv[h][0],ny=cy+mv[h][1],nc;
            if(cae[nx][ny]==0) nc=0;
            else nc=con+1;
            if(nc>k||vis[nx][ny]) continue;
            if(nx<1||nx>n||ny<1||ny>m) continue;
            que.push(qele(nx,ny,nc,st+1));
        }
    }
    return -1;
}
int main(){
    int _;
    cin>>_;
    while(_--) cout<<solve()<<endl;
    return 0;
}