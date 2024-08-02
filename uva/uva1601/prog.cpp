#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tiii;
const int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}},mask8=(1<<8)-1;
int w,h,n,idex[19][19],tot,tif[5],deb[5];
char cern[19][19];
vector<int> gr[361];
int vis[361][361][361];
int enco(int a,int b,int c){
    return (a<<16)+(b<<8)+c;
}
void deco(int h,int &a,int &b,int &c){
    a=h>>16,b=(h>>8)&mask8,c=h&mask8;
}
int solve(){
    tot=0;
    cin.get();
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            cern[i][j]=cin.get();
            if(cern[i][j]!='#'){
                idex[i][j]=++tot;
                gr[tot].clear();
                gr[tot].push_back(tot);
            }
        }
        cin.get();
    }
    for(int i=1;i<=h;++i) for(int j=1;j<=w;++j){
        if(cern[i][j]!='#'){
            int u=idex[i][j];
            for(int k=0;k<4;++k){
                int ii=i+mv[k][0],jj=j+mv[k][1];
                if(cern[ii][jj]!='#'){
                    int v=idex[ii][jj];
                    gr[u].push_back(v),gr[v].push_back(u);
                }
            }
        }
        if(isupper(cern[i][j])) tif[cern[i][j]-'A'+1]=idex[i][j];
        if(islower(cern[i][j])) deb[cern[i][j]-'a'+1]=idex[i][j];
    }
    for(int i=n+1;i<=3;++i) tif[i]=deb[i]=++tot,gr[tot].clear(),gr[tot].push_back(tot);
    queue<int> que;
    memset(vis,0xff,sizeof vis);
    que.push(enco(deb[1],deb[2],deb[3]));
    vis[deb[1]][deb[2]][deb[3]]=0;
    while(!que.empty()){
        int u,v,w,st;
        deco(que.front(),u,v,w),st=vis[u][v][w],que.pop();
        if(u==tif[1]&&v==tif[2]&&w==tif[3]) return st;
        for(int uu:gr[u]) for(int vv:gr[v]){
            if(uu==vv||(uu==v&&vv==u)) continue; 
            for(int ww:gr[w]){
                if(vv==ww||uu==ww) continue;
                if((uu==w&&ww==u)||(vv==w&&ww==v)) continue;
                int ext=enco(uu,vv,ww);
                if(vis[uu][vv][ww]!=-1) continue;
                vis[uu][vv][ww]=st+1;
                que.push(ext);
            }
        }
    }
    return 0xffffffff;
}
int main(){
    while(cin>>w>>h>>n&&(w||h||n)) cout<<solve()<<endl;
    return 0;
}