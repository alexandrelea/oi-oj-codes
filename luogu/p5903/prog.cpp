#include <iostream>
#include <vector>
#define ui unsigned int
ui s;
inline ui get(ui x){
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    return s=x;
}
#undef ui
using namespace std;
const int SIZE=5e5+10;
int n,q,fa[SIZE],dep[SIZE],siz[SIZE],r;
int wson[SIZE],toch[SIZE],dft=0,dfn[SIZE],ren[SIZE];
vector<int> edge[SIZE];
typedef long long lnt;
void dfs(int u,int fat,int dept){
    fa[u]=fat,siz[u]=1,dep[u]=dept;
    for(auto v:edge[u]){
        if(v==fat) continue;
        dfs(v,u,dept+1);
        siz[u]+=siz[v];
        if(siz[v]>siz[wson[u]]) wson[u]=v;
    }
}
void subd(int u,int t){
    toch[u]=t,dfn[u]=++dft,ren[dft]=u;
    if(wson[u]==0) return;
    subd(wson[u],t);
    for(auto v:edge[u]){
        if(v==fa[u]||v==wson[u]) continue;
        subd(v,v);
    }
}
int kthpar(int x,int k){
    int diff=dep[x]-k;
    while(dep[toch[x]]>diff) x=fa[toch[x]];
    diff=dep[x]-diff;
    return ren[dfn[x]-diff];
}
int main(){
    cin>>n>>q>>s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x!=0) edge[x].push_back(i),edge[i].push_back(x);
        else r=i;
    }
    dfs(r,0,1),subd(r,r);
    lnt lans=0,ans=0;
    for(int i=1;i<=q;i++){
        int x=((get(s)^lans)%n)+1,k=(get(s)^lans)%dep[x];
        lans=kthpar(x,k),ans^=(lans*(lnt)i);
        // cout<<x<<" "<<k<<" "<<lans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}