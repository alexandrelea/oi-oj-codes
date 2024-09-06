// UVa 11762 - Race to 1
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
bool vis[N];
int pr[N],cp;
double f[N];
double dp(int x){
    if(x==1) return 0;
    if(vis[x]) return f[x];
    vis[x]=1;
    double &ans=f[x]=0;
    int g=0,p=0;
    for(int i=1;i<=cp&&pr[i]<=x;++i,++p) if(x%pr[i]==0){
        ++g,ans+=dp(x/pr[i]);
    }
    return ans=(ans+p)/g;
}
void solve(int _){
    int n;
    cin>>n;
    cout<<"Case "<<_<<": "<<fixed<<setprecision(6)<<dp(n)<<endl;
}
int main(){
    int _,cc=0;
    cin>>_;
    for(int i=2;i<N;++i){
        if(!vis[i]) pr[++cp]=i;
        for(int j=1;j<=cp&&i*pr[j]<N;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    memset(vis,0,sizeof vis);
    while(_--) solve(++cc);
    return 0;
}