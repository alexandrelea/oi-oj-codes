#include <bits/stdc++.h>
using namespace std;
int n,vis[110];
double x[110],y[110],z[110],r[110],dis[110];
vector<pair<int,double>> gr[110];
priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
double hyp(double Dx,double Dy,double Dz){
    return sqrt(Dx*Dx+Dy*Dy+Dz*Dz);
}
double dist(double x1,double y1,double z1,double x2,double y2,double z2){
    return hyp(x1-x2,y1-y2,z1-z2);
}
double solve(){
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i]>>z[i]>>r[i],gr[i].clear();
    for(int i=n+1;i<=n+2;++i) cin>>x[i]>>y[i]>>z[i],gr[i].clear(),r[i]=0;
    for(int i=1;i<=n+2;++i) for(int j=i+1;j<=n+2;++j){
        double w=max(dist(x[i],y[i],z[i],x[j],y[j],z[j])-r[i]-r[j],0.0)*10.0;
        gr[i].push_back(make_pair(j,w)),gr[j].push_back(make_pair(i,w));
        // cerr<<i<<" "<<j<<" "<<w<<endl;
    }
    for(int i=1;i<=n+2;++i) dis[i]=1.0/0.0,vis[i]=0;
    dis[n+1]=0.0;
    pq.push(make_pair(dis[n+1],n+1));
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto edg:gr[u]){
            int v=edg.first;
            double w=edg.second;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push(make_pair(dis[v],v));
        }
    }
    return dis[n+2];
}
int main(){
    int _=0;
    while(cin>>n&&n!=-1) cout<<"Cheese "<<(++_)<<": Travel time = "<<(int)(solve()+0.5)<<" sec"<<endl;
    return 0;
}