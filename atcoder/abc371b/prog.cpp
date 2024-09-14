// ABC371B - Taro
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    bool vis[105];
    int n,m;
    cin>>n>>m;
    while(m--){
        int u;
        char ch;
        cin>>u>>ch;
        if(ch=='M'){
            if(!vis[u]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            vis[u]=1;
        }else cout<<"No"<<endl;
    }
    return 0;
}