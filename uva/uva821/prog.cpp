// UVa 821 - Page Hopping
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    string st;
    int u,v,_=0;
    double g[110][110];
    while(getline(cin,st)){
        map<int,int> cv;
        for(int i=1;i<=100;++i) for(int j=1;j<=100;++j) g[i][j]=(i==j?0:1.0/0.0);
        int __=0,tot=0;
        stringstream sin(st);
        while(sin>>u>>v){
            if(u==0&&v==0){
                if(__==0) return 0;
                else break;
            }
            if(!cv.count(u)) cv[u]=++tot;
            if(!cv.count(v)) cv[v]=++tot;
            u=cv[u],v=cv[v];
            g[u][v]=1,++__;
        }
        for(int k=1;k<=tot;++k) for(int i=1;i<=tot;++i) for(int j=1;j<=tot;++j){
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
        double ans=0,cnt=0;
        for(int i=1;i<=tot;++i) for(int j=1;j<=tot;++j){
            if(g[i][j]!=0) ans+=g[i][j],++cnt;
        }
        ans/=cnt;
        cout<<"Case "<<++_<<": average length between pages = "<<fixed<<setprecision(3)<<ans<<" clicks"<<endl;
    }
    return 0;
}