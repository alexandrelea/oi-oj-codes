// 洛谷 p2522 - [HAOI2011] Problem b
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int mu[N],pr[N],cp,muon[N];
bool vis[N];
void init(){
    vis[0]=vis[1]=1;
    mu[1]=muon[1]=1;
    for(int i=2;i<=5e4;++i){
        if(!vis[i]) pr[++cp]=i,mu[i]=-1;
        for(int j=1;j<=cp&&i*pr[j]<=5e4;++j){
            vis[i*pr[j]]=1;
            mu[i*pr[j]]=(i%pr[j]?-mu[i]:0);
            if(i%pr[j]==0) break;
        }
        muon[i]=muon[i-1]+mu[i];
    }
}
int statc(int n,int m){
    int ans=0;
    for(int i=1,j;i<=min(n,m);i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans+=(muon[j]-muon[i-1])*(n/i)*(m/i);
    }
    return ans;
}
int main(){
    init();
    int _;
    cin>>_;
    while(_--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        cout<<statc(b/k,d/k)-statc((a-1)/k,d/k)-statc(b/k,(c-1)/k)+statc((a-1)/k,(c-1)/k)<<endl;
    }
    return 0;
}