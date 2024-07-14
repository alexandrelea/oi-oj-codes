#include <bits/stdc++.h>
using namespace std;
const int N=210;
struct qnod{
    int v[3],dis;
    bool operator<(const qnod &rhs)const{
        return dis>rhs.dis;
    }
};
int vis[N][N],cap[3],ans[N];
void updans(qnod &u){
    for(int i=0;i<3;++i){
        int d=u.v[i];
        if(ans[d]<0||u.dis<ans[d]) ans[d]=u.dis;
    }
}
void solve(int a,int b,int c,int d){
    cap[0]=a,cap[1]=b,cap[2]=c;
    memset(vis,0,sizeof vis),memset(ans,0xff,sizeof ans);
    priority_queue<qnod> pq;
    qnod start;
    start.dis=0,start.v[0]=0,start.v[1]=0,start.v[2]=c;
    pq.push(start);
    vis[0][0]=1;
    while(!pq.empty()){
        qnod u=pq.top();pq.pop();
        updans(u);
        if(ans[d]>=0) break;
        for(int i=0;i<3;++i) for(int j=0;j<3;++j) if(i!=j){
            if(u.v[i]==0||u.v[j]==cap[j]) continue;
            int amo=min(cap[j],u.v[i]+u.v[j])-u.v[j];
            qnod u2;
            memcpy(&u2,&u,sizeof u);
            u2.dis=u.dis+amo,u2.v[i]-=amo,u2.v[j]+=amo;
            if(!vis[u2.v[0]][u2.v[1]]) vis[u2.v[0]][u2.v[1]]=1,pq.push(u2);
        }
    }
    while(d>=0) if(ans[d]>=0){
        cout<<ans[d]<<" "<<d<<endl;
        return;
    }else --d;
}
int main(){
    int _,a,b,c,d;
    cin>>_;
    while(_--) cin>>a>>b>>c>>d,solve(a,b,c,d);
    return 0;
}