#include <bits/stdc++.h>
using namespace std;
int n,fl[50][50],x=1,y=1,tot=1;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},w=0;
int main(){
    cin>>n;
    for(int i=0;i<=n+1;++i) fl[0][i]=fl[i][0]=fl[n+1][i]=fl[i][n+1]=-1;
    fl[n/2+1][n/2+1]=-1;
    while(tot<n*n-1){
        fl[x][y]=tot;
        while(fl[x+dir[w][0]][y+dir[w][1]]==0) x+=dir[w][0],y+=dir[w][1],fl[x][y]=++tot;
        w=(w+1)%4;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(fl[i][j]==-1) cout<<"T ";
            else cout<<fl[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}