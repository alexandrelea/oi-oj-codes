#include <bits/stdc++.h>
using namespace std;
struct qele{
    int nw,dis;
    qele(int nw=0,int dis=0):nw(nw),dis(dis){}
    bool operator<(const qele &rhs)const{
        return dis>rhs.dis;
    }
};
int dis[1<<22]={};
bool vis[1<<22]={};
priority_queue<qele> pq;
struct ap{
    int rm,cm,re,ce,w;
    bool operator<(const ap &rhs)const{
        return w<rhs.w;
    }
}p[110];
string bitout(int n,int nu){
    string r="";
    for(int i=0;i<n;++i) r.append(1,!!(nu&(1<<i))+'0');
    return r;
}
int solve(int n,int m){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    for(int i=1;i<=m;++i){
        cin>>p[i].w;
        p[i].rm=p[i].cm=p[i].re=p[i].ce=0;
        for(int j=0;j<n;++j){
            char ch;
            cin>>ch;
            if(ch!='0') p[i].rm|=(1<<j),p[i].re|=(ch=='-'?0:1)*(1<<j);
        }
        for(int j=0;j<n;++j){
            char ch;
            cin>>ch;
            if(ch!='0') p[i].cm|=(1<<j),p[i].ce|=(ch=='-'?0:1)*(1<<j);
        }
    }
    sort(p+1,p+m+1);
    // for(int i=1;i<=m;++i) cerr<<p[i].w<<" "<<bitout(n,p[i].rm)<<" "<<bitout(n,p[i].re)<<" "<<bitout(n,p[i].cm)<<" "<<bitout(n,p[i].ce)<<endl;
    int cur=(1<<n)-1;
    dis[cur]=0,pq.push(qele(cur,0));
    while(!pq.empty()){
        cur=pq.top().nw;pq.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        // cerr<<bitout(n,cur)<<" "<<dis[cur]<<endl;
        for(int i=1;i<=m;++i){        
            if(((cur^p[i].re)&p[i].rm)!=0) continue;
            int nxt=(cur&(~p[i].cm))|p[i].ce;
            // cerr<<bitout(n,nxt)<<" ";
            if(dis[cur]+p[i].w<dis[nxt]){
                dis[nxt]=dis[cur]+p[i].w;
                // cerr<<"used "<<dis[nxt];
                pq.push(qele(nxt,dis[nxt]));
            }
            // cerr<<endl;
        }
        // cerr<<endl;
    }
    return dis[0];
}
int main(){
    int n,m,_=0;
    while(cin>>n>>m&&(n!=0||m!=0)){
        cout<<"Product "<<(++_)<<endl;
        int ans=solve(n,m);
        if(ans==0x3f3f3f3f) cout<<"Bugs cannot be fixed."<<endl;
        else cout<<"Fastest sequence takes "<<ans<<" seconds."<<endl;
        cout<<endl;
    }
    return 0;
}