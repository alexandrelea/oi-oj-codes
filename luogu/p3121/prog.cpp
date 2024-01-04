#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char s[N],t[N],sk[N];
int n,tot,to[N][30],fail[N],last[N],wei[N];
int que[N],hd,tl,tp,su[N];
int ch2i(char ch){
    return ch-'a';
}
void insert(char *t){
    int u=0,l=strlen(t);
    for(int i=0;i<l;++i){
        if(to[u][ch2i(t[i])]==0) to[u][ch2i(t[i])]=++tot;
        u=to[u][ch2i(t[i])];
    }
    wei[u]=l;
}
void build(){
    for(int i=0;i<30;++i){
        if(to[0][i]!=0){
            int u=to[0][i];
            que[tl++]=u;
            fail[u]=last[u]=0;
        }
    }
    while(hd<tl){
        int u=que[hd++];
        for(int i=0;i<30;++i){
            if(to[u][i]==0) to[u][i]=to[fail[u]][i];
            else fail[to[u][i]]=to[fail[u]][i],que[tl++]=to[u][i],last[to[u][i]]=wei[fail[to[u][i]]]?fail[to[u][i]]:last[fail[to[u][i]]];
        }
    }
}
void query(){
    int l=strlen(s),u=0;
    for(int i=0;i<l;++i){
        sk[tp++]=s[i];
        int o=ch2i(s[i]);
        u=to[u][o];
        su[tp-1]=u;
        int v=u,popc=0;
        while(v!=0){
            if(wei[v]) popc=max(popc,wei[v]);
            v=last[v];
        }
        while(popc&&tp) --tp,--popc;
        u=su[tp-1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s>>n;
    for(int i=1;i<=n;++i) cin>>t,insert(t);
    build(),query();
    for(int i=0;i<tp;++i) cout<<sk[i];
    cout<<endl;
    return 0;
}