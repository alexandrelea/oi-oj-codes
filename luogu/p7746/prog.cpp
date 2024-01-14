#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,wg[N],fw[N],in[N],ot[N],dft=1;
vector<int> tr[N];
void dfs(int u){
    in[u]=++dft;
    for(int v:tr[u]) dfs(v);
    ot[u]=++dft;
}
void add(int x,int v){
    for(;x<=dft;x+=x&(-x)) fw[x]+=v;
}
int sum(int x){
    int ans=0;
    for(;x;x-=x&(-x)) ans+=fw[x];
    return ans;
}
signed main(){
    cin>>n>>m>>wg[1];
    for(int i=2;i<=n;++i){
        int fa;
        cin>>wg[i]>>fa;
        tr[fa].push_back(i);
    }
    dfs(1);
    while(m--){
        char o;
        int a,x;
        cin>>o>>a;
        if(o=='p') cin>>x,add(in[a]+1,x),add(ot[a],-x);
        else cout<<sum(in[a])+wg[a]<<endl;
    }
    return 0;
}