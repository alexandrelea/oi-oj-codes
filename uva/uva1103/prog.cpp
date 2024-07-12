#include <bits/stdc++.h>
using namespace std;
int h,k,w;
bool mes[210][210],cpy[210][210],cped[210][210],vis[210][210];
const int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
void flocpy(int x,int y){
    cped[x][y]=1;
    if(cpy[x][y]) return;
    cpy[x][y]=1;
    for(int co=0;co<8;++co){
        int nx=x+dir[co][0],ny=y+dir[co][1];
        if(0<=nx&&nx<=h+1&&0<=ny&&ny<=w+1&&mes[nx][ny]) flocpy(nx,ny);
    }
}
void flofil(int x,int y){
    if(vis[x][y]) return;
    vis[x][y]=1;
    for(int co=0;co<8;++co){
        int nx=x+dir[co][0],ny=y+dir[co][1];
        if(0<=nx&&nx<=h+1&&0<=ny&&ny<=w+1&&!cpy[x][y]) flofil(nx,ny);
    }
}
int holecnt(){
    int cnt=0;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=h;++i) for(int j=1;j<=w;++j) if(!vis[i][j]&&!cpy[i][j]){
        ++cnt;
        flofil(i,j);
    }
    return cnt;
}
void solve(){
    memset(cped,0,sizeof cped);
    memset(mes,0,sizeof mes);
    w=k*4;
    for(int i=1;i<=h;++i){
        string s;
        cin>>s;
        for(int j=0;j<k;++j){
            int u=s[j]-'0';
            if(u>=10) u-=39;
            mes[i][1+j*4]=!!(u&(1<<3));
            mes[i][2+j*4]=!!(u&(1<<2));
            mes[i][3+j*4]=!!(u&(1<<1));
            mes[i][4+j*4]=!!(u&(1<<0));
        }
    }
    string ans;
    for(int i=0;i<=h+1;++i) for(int j=0;j<=w+1;++j){
        if(mes[i][j]==1&&!cped[i][j]){
            memset(cpy,0,sizeof cpy);
            flocpy(i,j);
            // for(int i=1;i<=h;++i,cerr<<endl) for(int j=1;j<=w;++j) cerr<<cpy[i][j];
            int c=holecnt();
            // cerr<<c<<endl;
            if(c==1) ans+="W";
            if(c==2) ans+="A";
            if(c==3) ans+="K";
            if(c==4) ans+="J";
            if(c==5) ans+="S";
            if(c==6) ans+="D";
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main(){
    int _=0;
    while(cin>>h>>k&&(h||k)) cout<<"Case "<<(++_)<<": ",solve();
    return 0;
}