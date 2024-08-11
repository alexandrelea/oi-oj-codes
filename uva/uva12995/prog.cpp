// UVa12995 - Farey Sequence
// Code by Alexanderia Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int pr[N],pc,phi[N],n;
bool vis[N];
signed main(){
    vis[0]=vis[1]=1,phi[1]=1;
    for(int i=2;i<=N-5;++i){
        if(!vis[i]) pr[++pc]=i,phi[i]=i-1;
        for(int j=1;j<=pc&&i*pr[j]<=N-5;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0){
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
            phi[i*pr[j]]=phi[i]*phi[pr[j]];
        }
    }
    for(int i=1;i<=N-5;++i) phi[i]+=phi[i-1];
    while(cin>>n&&n) cout<<phi[n]-1<<endl;
    return 0;
}