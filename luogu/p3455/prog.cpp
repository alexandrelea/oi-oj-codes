// 洛谷 p3455 - [POI2007] ZAP-Queries
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
typedef long long ll;
bool vis[N];
int pr[N],cp,mu[N],mus[N];
int main(){
    mu[1]=mus[1]=1;
    for(int i=2;i<=5e4;++i){
        if(!vis[i]) pr[++cp]=i,mu[i]=-1;
        for(int j=1;j<=cp&&i*pr[j]<=5e4;++j){
            vis[i*pr[j]]=1;
            mu[i*pr[j]]=(i%pr[j]?-mu[i]:0);
            if(i%pr[j]==0) break;
        }
        mus[i]=mu[i]+mus[i-1];
    }
    int _;
    cin>>_;
    while(_--){
        int n,m,k;
        ll ans=0;
        cin>>n>>m>>k;
        n/=k,m/=k;
        if(n<m) swap(n,m);
        for(int i=1,j;i<=m;i=j+1){
            j=min(n/(n/i),m/(m/i));
            ans+=(mus[j]-mus[i-1])*(ll)(n/i)*(m/i);
        }
        cout<<ans<<endl;
    }
    return 0;
}