#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,S=30;
int tot,que[N],hd,tl,sat[N],n,fa[N],m;
int to[N][30],se[N],wei[N],fail[N],ans[N];
int dfn[N],out[N],dft=-1,sum[N];
char s[N];
vector<int> tr[N];
struct task{
    int x,y,id;
    task(int x,int y,int id):x(x),y(y),id(id){}
    bool operator<(const task &rhs)const{
        return y<rhs.y;
    }
};
vector<task> ask;
int ch2i(char ch){
    return ch-'a';
}
void dfs(int u,int fh){
    dfn[u]=++dft;
    for(int v:tr[u]){
        if(v==fh) continue;
        dfs(v,u);
    }
    out[u]=dft;
}
void build(){
    for(int i=0;i<S;++i){
        if(to[0][i]==0) continue;
        int v=to[0][i];
        que[tl++]=v,fail[v]=0;
    }
    while(hd<tl){
        int u=que[hd++];
        for(int o=0;o<S;++o){
            if(to[u][o]==0) to[u][o]=to[fail[u]][o];
            else fail[to[u][o]]=to[fail[u]][o],que[tl++]=to[u][o];
        }
    }
    for(int i=1;i<=tot;++i) tr[fail[i]].push_back(i);
    dfs(0,0);
}
void add(int x,int w){
    for(;x<=tot;x+=x&-x) sum[x]+=w;
}
int get(int x){
    int ans=0;
    for(;x;x-=x&-x) ans+=sum[x];
    return ans;
}
int main(){
    int u,l,k,f;
    cin>>s;
    l=strlen(s),u=0;
    for(int i=0;i<l;++i){
        if(s[i]=='P') sat[++n]=u,wei[u]=n;
        else if(s[i]=='B') u=fa[u];
        else{
            int o=ch2i(s[i]);
            if(to[u][o]==0) to[u][o]=++tot,fa[to[u][o]]=u;
            u=to[u][o];
        }
    }
    build();
    cin>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        ask.push_back(task(x,y,i));
    }
    sort(ask.begin(),ask.end());
    u=k=f=0;
    for(int i=0;i<l;++i){
        if(s[i]>='a'&&s[i]<='z') u=to[u][ch2i(s[i])],add(dfn[u],1);
        else if(s[i]=='P'){
            ++k;
            for(int j=f;ask[j].y==k;++j)
                ans[ask[j].id]+=get(out[sat[ask[j].x]])-get(dfn[sat[ask[j].x]]-1),f=j;
            if(ask[f].y==k) ++f;
        }else if(s[i]=='B') add(dfn[u],-1),u=fa[u];
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<endl;
    return 0;
}