// UVa 10285 - Longest Run on a Snowboard
// Code by Alexandre Lea
#include <iostream>
#include <map>
using namespace std;
string nam;
int r,c,hei[101][101];
map<pair<int,int>,int> mono;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dp(int x,int y){
    if(mono.count(make_pair(x,y))) return mono[make_pair(x,y)];
    int ans=1;
    for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(nx<1||nx>r||ny<1||ny>c) continue;
        if(hei[nx][ny]<hei[x][y]) ans=max(ans,dp(nx,ny)+1);
    }
    return mono[make_pair(x,y)]=ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>nam>>r>>c;
        mono.clear();
        for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) cin>>hei[i][j];
        int ans=0;
        for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) ans=max(ans,dp(i,j));
        cout<<nam<<": "<<ans<<endl;
    }
    return 0;
}