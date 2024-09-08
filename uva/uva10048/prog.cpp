// UVa 10048 - Audiophobia
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int c,s,q,gr[105][105];
void solve(int _){
    memset(gr,0x3f,sizeof(gr));
    while(s--){
        int u,v,w;
        cin>>u>>v>>w;
        gr[u][v]=gr[v][u]=w;
    }
    for(int k=1;k<=c;++k) for(int i=1;i<=c;++i) for(int j=1;j<=c;++j){
        gr[i][j]=min(gr[i][j],max(gr[i][k],gr[k][j]));
    }
    if(_!=1) cout<<endl;
    cout<<"Case #"<<_<<endl;
    while(q--){
        int u,v;
        cin>>u>>v;
        if(gr[u][v]==0x3f3f3f3f) cout<<"no path"<<endl;
        else cout<<gr[u][v]<<endl;
    }
}
int main(){
    int _=0;
    while(cin>>c>>s>>q&&(c||s||q)) solve(++_);
    return 0;
}