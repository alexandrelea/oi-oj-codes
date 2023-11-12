#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
lnt a,b,pw[13]={1},f[15],p[15],now[15];
lnt dfs(int u,int x,bool f0,bool lim){
    if(u==0){
        if(f0) f0=0;
        return 0;
    }
    if((!lim)&&(!f0)&&(f[u]!=-1)) return f[u];
    lnt cnt=0;
    int lst=lim?p[u]:9;
    for(int i=0;i<=lst;i++){
        if(f0&&i==0) cnt+=dfs(u-1,x,1,lim&&i==lst);
        else if(i==x&&lim&&i==lst) cnt+=now[u-1]+1+dfs(u-1,x,0,lim&&i==lst);
        else if(i==x) cnt+=pw[u-1]+dfs(u-1,x,0,lim&&i==lst);
        else cnt+=dfs(u-1,x,0,lim&&i==lst);
    }
    if((!lim)&&(!f0)) f[u]=cnt;
    return cnt;
}
lnt gans(lnt d,int dig){
    int len=0;
    memset(f,-1,sizeof(f));
    while(d) p[++len]=d%10,d/=10,now[len]=now[len-1]+p[len]*pw[len-1];
    return dfs(len,dig,1,1);
}
int main(){
    cin>>a>>b;
    for(int i=1;i<=12;i++) pw[i]=pw[i-1]*10ll;
    for(int i=0;i<=9;i++) cout<<gans(b,i)-gans(a-1,i)<<" ";
    return 0;
}