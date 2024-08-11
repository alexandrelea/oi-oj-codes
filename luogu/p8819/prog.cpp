#include <iostream>
#include <random>
using namespace std;
// ifstream cin("galaxy.in");
// ofstream cout("galaxy.out");
typedef unsigned long long ulnt;
const int SIZE=5e5+10;
random_device rd;
mt19937_64 rnd(rd());
ulnt stnd,tmp,val[SIZE],sum[SIZE],_sum[SIZE];
int main(){
    int n,m,q;
    cin>>n>>m;
    for(int i=1;i<=n;i++) stnd+=(val[i]=rnd());
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        _sum[v]=(sum[v]+=val[u]),tmp+=val[u];
    }
    cin>>q;
    while(q--){
        int t,u,v;
        cin>>t>>u;
        if(t==1||t==3) cin>>v;
        if(t==1) tmp-=val[u],sum[v]-=val[u];
        if(t==2) tmp-=sum[u],sum[u]=0;
        if(t==3) tmp+=val[u],sum[v]+=val[u];
        if(t==4) tmp+=_sum[u]-sum[u],sum[u]=_sum[u];
        cout<<(tmp==stnd?"YES":"NO")<<endl;
    }
    return 0;
}