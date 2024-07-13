#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int tot=0,to[N][30],wit[N],same[N],fail[N],vis[N];
int que[N],hd,tl,in[N],ans[N];
char s[N],t[N];
void insert(int id){
    int l=strlen(t),u=0;
    for(int i=0;i<l;++i){
        if(to[u][t[i]-'a']==0) to[u][t[i]-'a']=++tot;
        u=to[u][t[i]-'a'];
    }
    if(wit[u]==0) wit[u]=id,same[wit[u]]=wit[u];
    else same[id]=wit[u];
}
void build(){
    for(int c=0;c<30;++c){
        if(to[0][c]==0) continue;
        int u=to[0][c];
        que[tl++]=u,fail[u]=0;
    }
    while(hd<tl){
        int u=que[hd++];
        for(int c=0;c<30;++c){
            if(to[u][c]==0) to[u][c]=to[fail[u]][c];
            else fail[to[u][c]]=to[fail[u]][c],que[tl++]=to[u][c],++in[fail[to[u][c]]];
        }
    }
}
void query(){
    int l=strlen(s),u=0;
    for(int i=0;i<l;++i){
        u=to[u][s[i]-'a'];
        ++ans[u];
    }
}
void topo(){
    hd=tl=0;
    for(int i=0;i<=tot;++i) if(in[i]==0) que[tl++]=i;
    while(hd<tl){
        int u=que[hd++],v=fail[u];
        vis[wit[u]]=ans[u],--in[v];
        ans[v]+=ans[u];
        if(in[v]==0) que[tl++]=v;
    }
}
int main(){
    int q;
    scanf("%s%d",s,&q);
    for(int i=1;i<=q;++i) scanf("%s",t),insert(i);
    build(),query(),topo();
    for(int i=1;i<=q;++i) printf("%d\n",vis[same[i]]);
    return 0;
}