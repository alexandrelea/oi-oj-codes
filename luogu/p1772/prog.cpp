#include <iostream>
#include <cstring>
using namespace std;
typedef long long lnt;
const int SIZE=30;
const lnt INF=2e5+10;
int n,m,k,e,d;
lnt sea[SIZE][SIZE],st[105],ed[105],po[105],ans[105][105],f[105];
bool use[SIZE];
lnt dijkstra(){
    int start,end;
    lnt dist[SIZE];
    bool went[SIZE];
    for(int i=1;i<=m;i++) dist[i]=sea[1][i],went[i]=false;
    dist[1]=0,went[1]=true;
    for(int i=2;i<=m;i++){
        int tmp=INF;
        for(int j=1;j<=m;j++){
            if(sea[i][j]!=INF&&!went[j]&&tmp>dist[j]&&use[j]){
                tmp=dist[j],start=j;
            }
        }
        went[start]=true;
        for(end=1;end<=m;end++) if(sea[start][end]!=INF&&start!=end) dist[end]=min(dist[end],dist[start]+sea[start][end]);
    }
    return dist[m];
}
int main(){
    cin>>n>>m>>k>>e;
    for(int i=0;i<SIZE;i++) for(int j=0;j<SIZE;j++) sea[i][j]=INF;
    for(int i=0;i<e;i++){
        int x,y,c;
        cin>>x>>y>>c;
        sea[x][y]=sea[y][x]=c;
    }
    cin>>d;
    for(int i=1;i<=d;i++){
        int p,a,b;
        cin>>p>>a>>b;
        st[i]=a,ed[i]=b,po[i]=p;
    }
    memset(ans,0,sizeof(ans));
    for(int l=0;l<=n;l++){
        for(int i=1;i+l<=n;i++){
            for(int j=0;j<=SIZE;j++) use[j]=true;
            for(int j=1;j<=d;j++){
                for(int k=i;k<=i+l;k++){
                    if(k>=st[j]&&k<=ed[j]) use[po[j]]=false;
                }
            }
            ans[i][i+l]+=dijkstra();
        }
    }
    f[0]=0,f[1]=ans[1][1];
    for(int i=2;i<=n;i++){
        f[i]=ans[1][i]*i;
        for(int j=i-1;j>=0;j--) f[i]=min(f[i],f[j]+ans[j+1][i]*(i-j)+k);
    }
    cout<<f[n]<<endl;
    return 0;
}