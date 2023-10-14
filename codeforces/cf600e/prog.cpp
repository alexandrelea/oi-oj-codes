#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int SIZE=1e5+10;
int n,r,col[SIZE];
vector<int> edge[SIZE];
int dep[SIZE],fa[SIZE],siz[SIZE];
int wson[SIZE],apr[SIZE],mx,sum,ans[SIZE];
void dfs(int u,int fah,int dept){
    fa[u]=fah,siz[u]=1,dep[u]=dept;
    for(auto v:edge[u]){
        if(v==fah) continue;
        dfs(v,u,dept+1);
        siz[u]+=siz[v];
        if(siz[wson[u]]<siz[v]) wson[u]=v;
    }
}
void bru(int u,int ws){
    apr[col[u]]++;
    if(apr[col[u]]>mx) mx=apr[col[u]],sum=col[u];
    else if(apr[col[u]]==mx) sum+=col[u];
    for(auto v:edge[u]){
        if(v==fa[u]||v==ws) continue;
        bru(v,ws);
    }
}
void init(int u){
    apr[col[u]]--;
    for(auto v:edge[u]){
        if(v==fa[u]) continue;
        init(v);
    }
}
void dsu(int u){
    for(auto v:edge[u]){
        if(v==wson[u]||v==fa[u]) continue;
        dsu(v);
        init(v),sum=mx=0;
    }
    if(wson[u]!=0) dsu(wson[u]);
    bru(u,wson[u]);
    ans[u]=sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y),edge[y].push_back(x);
    }
    dfs(1,0,1),dsu(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}