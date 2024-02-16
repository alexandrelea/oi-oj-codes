#include <bits/stdc++.h>
using namespace std;
const int N=1510;
int n,f[N][2];
vector<int> tr[N];
void dp(int u,int pr){
    f[u][1]=1,f[u][0]=0;
    for(int v:tr[u]){
        if(v==pr) continue;
        dp(v,u);
        f[u][0]+=f[v][1];
        f[u][1]+=min(f[v][1],f[v][0]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int h,k,u;
        cin>>h>>k;
        while(k--) cin>>u,tr[h].push_back(u),tr[u].push_back(h);
    }
    dp(1,-1);
    cout<<min(f[1][0],f[1][1])<<endl;
    return 0;
}