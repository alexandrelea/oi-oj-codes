// ABC368D - Minimum Steiner Tree
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2'00'005;
int n,fa[N][17],dep[N],k,x;
vector<int> tr[N];
set<int> son[N],requ;
void dfs(int u,int f){
    fa[u][0]=f,dep[u]=dep[f]+1;
    for(int v:tr[u]){
        if(v==f) continue;
        son[u].insert(v);
        dfs(v,u);
    }
}
int cnt(int u){
    bool cont=0;
    int ans=0;
    for(int v:son[u]){
        int re=cnt(v);
        if(re!=0) cont=1;
        ans+=re;
    }
    ans+=(cont||requ.count(u));
    // cerr<<"c "<<u<<" = "<<ans<<endl;
    return ans;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v),tr[v].push_back(u);
    }
    for(int i=1;i<=k;++i){
        cin>>x;
        requ.insert(x);
    }
    dfs(*requ.begin(),0);
    cout<<cnt(*requ.begin())<<endl;
    return 0;
}