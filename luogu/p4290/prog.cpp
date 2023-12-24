#include <bits/stdc++.h>
using namespace std;
char ss[210];
int m[127],s[5],n;
bool ok[5][5][5],f[210][210][5],flag;
int main(){
    m['W']=1,m['I']=2,m['N']=3,m['G']=4;
    for(int i=1;i<=4;++i) cin>>s[i];
    for(int i=1;i<=4;++i){
        for(int j=1;j<=s[i];++j){
            char a,b;
            cin>>a>>b;
            ok[m[a]][m[b]][i]=1;
        }
    }
    cin>>ss;
    n=strlen(ss);
    for(int i=1;i<=n;++i) f[i][i][m[ss[i-1]]]=1;
    for(int l=2;l<=n;++l) for(int i=1;i<=n-l+1;++i){
        int j=i+l-1;
        for(int k=i;k<j;++k) for(int x=1;x<=4;++x) for(int y=1;y<=4;++y) for(int z=1;z<=4;++z) if(f[i][k][y]&&f[k+1][j][z]&&ok[y][z][x]) f[i][j][x]=1;
    }
    if(f[1][n][1]) flag=true,cout<<'W';
    if(f[1][n][2]) flag=true,cout<<'I';
    if(f[1][n][3]) flag=true,cout<<'N';
    if(f[1][n][4]) flag=true,cout<<'G';
    if(!flag) cout<<"The name is wrong!"<<endl;
    return 0;
}