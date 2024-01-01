#include <bits/stdc++.h>
using namespace std;
int n,hd,tl,que[10550],cnt[155],ans;
int tot,to[10550][30],fail[10550],wei[10550],last[10550];
char s[155][75],t[1000005];
void clean(){
    tot=hd=tl=ans=0;
    memset(s,0,sizeof(s));
    memset(t,0,sizeof(t));
    memset(to,0,sizeof(to));
    memset(fail,0,sizeof(fail));
    memset(wei,0,sizeof(wei));
    memset(que,0,sizeof(que));
    memset(last,0,sizeof(last));
    memset(cnt,0,sizeof(cnt));
}
int ch2i(char ch){
    return ch-'a';
}
void insert(int id){
    int u=0,l=strlen(s[id]);
    for(int i=0;i<l;++i){
        if(to[u][ch2i(s[id][i])]==0) to[u][ch2i(s[id][i])]=++tot;
        u=to[u][ch2i(s[id][i])];
    }
    wei[u]=id;
}
void build(){
    for(int i=0;i<26;++i){
        if(to[0][i]!=0) que[tl++]=to[0][i],fail[to[0][i]]=last[to[0][i]]=0;
    }
    while(hd<tl){
        int u=que[hd++];
        for(int c=0;c<26;++c){
            if(to[u][c]==0) continue;
            int v=to[u][c],f=fail[u];
            while(f!=0&&to[f][c]==0) f=fail[f];
            fail[v]=to[f][c];
            que[tl++]=v;
            last[v]=wei[fail[v]]?fail[v]:last[fail[v]];
        }
    }
}
void query(){
    int l=strlen(t),u=0;
    for(int i=0;i<l;++i){
        int c=ch2i(t[i]);
        while(u!=0&&to[u][c]==0) u=fail[u];
        u=to[u][c];
        int v=u;
        while(v!=0){
            if(wei[v]) ++cnt[wei[v]];
            v=last[v];
        }
    }
}
int main(){
    while(cin>>n&&n!=0){
        clean();
        for(int i=1;i<=n;++i) cin>>s[i],insert(i);
        build();
        cin>>t;
        query();
        ans=1;
        for(int i=2;i<=n;++i) if(cnt[i]>cnt[ans]) ans=i;
        cout<<cnt[ans]<<endl;
        for(int i=1;i<=n;++i) if(cnt[i]==cnt[ans]) cout<<s[i]<<endl;
    }
    return 0;
}