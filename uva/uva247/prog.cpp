// UVa 247 - Calling Circles
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool ca[27][27],vis[27];
void solve(int _){
    int cnt=0;
    map<string,int> n2i;
    map<int,string> i2n;
    memset(ca,0,sizeof(ca));
    memset(vis,0,sizeof(vis));
    while(m--){
        string a,b;
        cin>>a>>b;
        if(!n2i.count(a)) n2i[a]=++cnt,i2n[cnt]=a;
        if(!n2i.count(b)) n2i[b]=++cnt,i2n[cnt]=b;
        ca[n2i[a]][n2i[b]]=1;
    }
    for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ca[i][j]|=ca[i][k]&&ca[k][j];
    cout<<"Calling circles for data set "<<_<<":"<<endl;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        queue<int> que;
        que.push(i),vis[i]=1;
        for(int j=i+1;j<=n;++j) if(ca[i][j]&&ca[j][i]) que.push(j),vis[j]=1;
        while(que.size()!=1) cout<<i2n[que.front()]<<", ",que.pop();
        cout<<i2n[que.front()]<<endl;
    }
    
}
int main(){
    int _=0;
    while(cin>>n>>m&&(n||m)) solve(++_);
    return 0;
}