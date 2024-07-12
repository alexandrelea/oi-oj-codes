#include <bits/stdc++.h>
using namespace std;
const int N=200;
int n;
char buf[N+10][N+10];
void dfs(int r,int c){
    cout<<buf[r][c]<<"(";
    if(r+1<n&&buf[r+1][c]=='|'){
        int i=c;
        while(i-1>=0&&buf[r+2][i-1]=='-') --i;
        while(buf[r+2][i]=='-'&&buf[r+3][i]!='\0'){
            if(!isspace(buf[r+3][i])) dfs(r+3,i);
            ++i;
        }
    }
    cout<<")";
}
void solve(){
    n=0;
    for(;;){
        fgets(buf[n],N+10,stdin);
        if(buf[n][0]=='#') break;
        else ++n;
    }
    cout<<"(";
    if(n) for(int i=0;i<strlen(buf[0]);++i) if(buf[0][i]!=' '){
        dfs(0,i);
        break;
    }
    cout<<")"<<endl;
}
int main(){
    int _;
    fgets(buf[0],N+10,stdin);
    sscanf(buf[0],"%d",&_);
    while(_--) solve();
    return 0;
}