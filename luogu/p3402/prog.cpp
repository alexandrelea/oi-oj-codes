#include <iostream>
#include <vector>
using namespace std;
const int size=1e6+10;
int n,fa[size]={},siz[size]={},stk[size]={},ct=0;
int dfn[size]={},ty[size]={},ans[size]={},a[size]={},b[size]={},m;
void init(){
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
}
int f(int x){
    return fa[x]==x?fa[x]:f(fa[x]);
}
void u(int x,int y){
    x=f(x),y=f(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y); //siz[x]>=siz[y]
    stk[++ct]=y,fa[y]=x,siz[x]+=siz[y]; 
}
void d(){
    if(ct==0) return;
    int y=stk[ct--];
    siz[fa[y]]-=siz[y],fa[y]=y;
}
void bk(int t=0){
    while(ct>t) d();
}
vector<int> edgs[size];
void dfs(int x){
    dfn[x]=ct;
    if(ty[x]==3) ans[x]=(f(a[x])==f(b[x]));
    if(ty[x]==1) u(a[x],b[x]);
    for(auto y:edgs[x]) dfs(y);
    bk(dfn[x]);
}
int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        cin>>ty[i]>>a[i];
        if(ty[i]!=2) cin>>b[i],edgs[i-1].push_back(i);
        else edgs[a[i]].push_back(i);
    }
    dfs(0);
    for(int i=1;i<=m;i++) if(ty[i]==3) cout<<ans[i]<<endl;
    return 0;
}