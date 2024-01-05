#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char t[N],s[N*10];
int n,tot,que[N],hd,tl,in[N],ans[N];
int to[N][30],fail[N],vis[N],wei[N],same[N];
int ch2i(char ch){
    return ch-'a';
}
void insert(int id){
    int u=0,l=strlen(t);
    for(int i=0;i<l;++i){
        int o=ch2i(t[i]);
        if(to[u][o]==0) to[u][o]=++tot;
        u=to[u][o];
    }
    if(wei[u]==0) wei[u]=id,same[wei[u]]=wei[u];
    else same[id]=wei[u];
}
void build(){
    for(int o=0;o<30;++o){
        if(to[0][o]==0) continue;
        int u=to[0][o];
        que[tl++]=u,fail[u]=0;
    }
    while(hd<tl){
        int u=que[hd++];
        for(int o=0;o<30;++o){
            if(to[u][o]==0) to[u][o]=to[fail[u]][o];
            else fail[to[u][o]]=to[fail[u]][o],que[tl++]=to[u][o],++in[fail[to[u][o]]];
        }
    }
}
void query(){
    int l=strlen(s),u=0;
    for(int i=0;i<l;++i){
        u=to[u][ch2i(s[i])];
        ++ans[u];
    }
}
void topo(){
    hd=tl=0;
    for(int i=0;i<=tot;++i) if(in[i]==0) que[tl++]=i;
    while(hd<tl){
        int u=que[hd++],v=fail[u];
        vis[wei[u]]=ans[u],--in[v];
        ans[v]+=ans[u];
        if(in[v]==0) que[tl++]=v;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t;
        insert(i);
    }
    build();
    cin>>s;
    query();
    topo();
    for(int i=1;i<=n;++i) cout<<vis[same[i]]<<endl;
    return 0;
}