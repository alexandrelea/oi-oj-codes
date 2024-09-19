// 洛谷 p2346 - 四子连棋
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
char K[4][4];
int dep=0,mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool aeq(char a,char b,char c,char d){
    return a==b&&b==c&&c==d;
}
bool dfs(int step,char py){
    if(step==dep){
        return aeq(K[0][0],K[0][1],K[0][2],K[0][3])
             ||aeq(K[1][0],K[1][1],K[1][2],K[1][3])
             ||aeq(K[2][0],K[2][1],K[2][2],K[2][3])
             ||aeq(K[3][0],K[3][1],K[3][2],K[3][3])
             ||aeq(K[0][0],K[1][0],K[2][0],K[3][0])
             ||aeq(K[0][1],K[1][1],K[2][1],K[3][1])
             ||aeq(K[0][2],K[1][2],K[2][2],K[3][2])
             ||aeq(K[0][3],K[1][3],K[2][3],K[3][3])
             ||aeq(K[0][0],K[1][1],K[2][2],K[3][3])
             ||aeq(K[0][3],K[1][2],K[2][1],K[3][0]);
    }
    for(int x=0;x<4;++x) for(int y=0;y<4;++y){
        if(K[x][y]=='O'){
            for(int c=0;c<4;++c){
                int xx=mov[c][0]+x,yy=mov[c][1]+y;
                if(0<=xx&&xx<4&&0<=yy&&yy<4&&K[xx][yy]==py){
                    swap(K[x][y],K[xx][yy]);
                    if(dfs(step+1,(py=='B'?'W':'B'))) return 1;
                    swap(K[x][y],K[xx][yy]);
                }
            }
        }
    }
    return 0;
}
int main(){
    for(int i=0;i<=3;++i) for(int j=0;j<=3;++j) cin>>K[i][j];
    for(dep=0;;++dep) if(dfs(0,'B')||dfs(0,'W')){
        cout<<dep<<endl;
        return 0;
    }
    return 0;
}