// ABC368F - Dividing Game
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1'00'005;
int n,x,ax,pr[N],cp,mx[N],a;
bool vis[N];
int main(){
    mx[1]=1;
    memset(mx,0x3f,sizeof mx);
    for(int i=2;i<=1e5;++i){
        if(!vis[i]) pr[++cp]=i,mx[i]=i;
        for(int j=1;j<=cp&&i*pr[j]<=1e5;++j){
            vis[i*pr[j]]=1,mx[i*pr[j]]=min(pr[j],mx[i*pr[j]]);
            if(i%pr[j]==0) break;
        }
    }
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x,a=0;
        while(x!=1) x/=mx[x],++a;
        ax^=a;
    }
    if(ax==0) cout<<"Bruno"<<endl;
    else cout<<"Anna"<<endl;
    return 0;
}