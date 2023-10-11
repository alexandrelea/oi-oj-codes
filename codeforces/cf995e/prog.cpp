#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#pragma GCC optimize(2)
using namespace std;
int mul(int a,int b,int p){
    int ans=0;
    for(;b;a=a*2%p,b>>=1) if(b&1) ans=(ans+a)%p;
    return ans;
}
int pow(int a,int b,int p){
    int ans=1;
    for(;b;a=mul(a,a,p),b>>=1) if(b&1) ans=mul(ans,a,p);
    return ans;
}
int fn(int x,int p,int ty){
    if(ty==0) return (x+1+p)%p;
    else if(ty==1) return (x-1+p)%p;
    else return pow(x,p-2,p);
}
int ces(int x,int y,int p){
    if(fn(x,p,0)==y) return 1;
    else if(fn(x,p,1)==y) return 2;
    else return 3;
}
int main(){
    int u,v,p,ni,co;
    map<int,int> from,fa,stp;
    queue<int> que;
    vector<int> ans;

    cin>>u>>v>>p;
    
    if(u==v){
        cout<<0<<endl;
        return 0;
    }
    from[u]=1,from[v]=2;
    fa[u]=u,fa[v]=v;
    stp[u]=0,stp[v]=1;
    que.push(u),que.push(v);
    while(!que.empty()){
        int nw=que.front();que.pop();
        bool got=false;
        for(int o=0;o<3;o++){
            int xt=fn(nw,p,o);
            if(from[xt]==from[nw]) continue;
            if(from[xt]+from[nw]==3){
                ni=xt,co=nw;
                got=true;
                break;
            }
            from[xt]=from[nw];
            stp[xt]=stp[nw]+1;
            fa[xt]=nw;
            que.push(xt);
        }
        if(got) break;
    }

    cout<<stp[ni]+stp[co]<<endl;
    if(from[ni]==1&&from[co]==2){
        // u---ni-co---v
        while(fa[ni]!=ni) ans.push_back(ni),ni=fa[ni];
        ans.push_back(ni);
        reverse(ans.begin(),ans.end());
        ans.push_back(co);
        while(fa[co]!=co) ans.push_back(fa[co]),co=fa[co];
    }else{
        // u---co-ni---v
        while(fa[co]!=co) ans.push_back(co),co=fa[co];
        ans.push_back(co);
        reverse(ans.begin(),ans.end());
        ans.push_back(ni);
        while(fa[ni]!=ni) ans.push_back(fa[ni]),ni=fa[ni];
    }
    for(int i=0;i<ans.size()-1;i++) cout<<ces(ans[i],ans[i+1],p)<<" ";
    return 0;
}