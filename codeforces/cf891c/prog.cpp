#include <iostream>
#include <algorithm>
using namespace std;
const int size=5e5+10;
int n,m,q,ans[size],alq,id=1;
struct edg{
    int u,v,w;
    int id;
}edgs[size],bp[size];
struct quon{
    int ed,id;
}quos[size];
bool cmpe(edg a,edg b){
    return a.w<b.w;
}
bool cmpq(quon a,quon b){
    if(bp[a.ed].w==bp[b.ed].w) return a.id<b.id;
    else return bp[a.ed].w<bp[b.ed].w;
}
int fa[size],sz[size],stck[size],top=0;
int find(int x){
    return fa[x]==x?fa[x]:find(fa[x]);
}
void unino(int x,int y,bool back=false){
    x=find(x),y=find(y);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x],fa[x]=y;
    if(back) stck[++top]=x;
}
void quash(){
    if(top==0) return;
    int x=stck[top--];
    sz[fa[x]]-=sz[x],fa[x]=x;
}
void bck(){
    while(top>0) quash();
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edgs[i]={u,v,w,i};
        bp[i]=edgs[i];
    }
    sort(edgs+1,edgs+m+1,cmpe);
    cin>>q;
    for(int i=1;i<=q;i++){
        int k,x;
        ans[i]=true;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>x,quos[++alq]={x,i};
    }
    sort(quos+1,quos+alq+1,cmpq);
    for(int i=1;i<=alq;i++){ 
        if(ans[quos[i].id]==false) continue; // Already delete this question.
        if(i>1&&(bp[quos[i-1].ed].w!=bp[quos[i].ed].w||quos[i-1].id!=quos[i].id)) bck();
        while(id<=m&&edgs[id].w<bp[quos[i].ed].w) unino(edgs[id].u,edgs[id].v),++id;
        if(find(bp[quos[i].ed].u)==find(bp[quos[i].ed].v)) ans[quos[i].id]=false;
        else unino(bp[quos[i].ed].u,bp[quos[i].ed].v,true);
    }
    for(int i=1;i<=q;i++) if(ans[i]) cout<<"YES\n"; else cout<<"NO\n";
    return 0;
}