// UVa 1676 - GRE Words Revenge
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=((int)5e6)+5;
typedef long long ll;
int to[N][2],too[N][2],te[N],ro[N],vis[N],sz[N],tot,cnt;
ll f[N];
void newstr(string s,int &r){
    if(r==0) r=++tot;
    int u=r;
    for(auto ch:s){
        if(to[u][ch-'0']==0) to[u][ch-'0']=++tot;
        u=to[u][ch-'0'];
    }
    vis[u]|=1;
}
int merge(int u,int v){
    if(u==0||v==0) return u+v;
    vis[u]+=vis[v];
    for(int i=0;i<=1;++i) to[u][i]=merge(to[u][i],to[v][i]);
    return u;
}
void build(int r){
    queue<int> que;
    te[r]=r;
    for(int i=0;i<=1;++i){
        if(to[r][i]!=0) too[r][i]=to[r][i],te[too[r][i]]=r,que.push(too[r][i]);
        else too[r][i]=r;
    }
    while(!que.empty()){
        int u=que.front();que.pop();
        f[u]=vis[u]+f[te[u]];
        for(int i=0;i<=1;++i){
            if(to[u][i]) too[u][i]=to[u][i],te[too[u][i]]=too[te[u]][i],que.push(to[u][i]);
            else too[u][i]=too[te[u]][i];
        }
    }
}
set<string> re;
void insert(string s){
    if(re.count(s)) return;
    re.insert(s);
    sz[++cnt]=1;
    newstr(s,ro[cnt]);
    while(sz[cnt-1]==sz[cnt]) sz[cnt-1]+=sz[cnt],ro[cnt-1]=merge(ro[cnt-1],ro[cnt]),ro[cnt]=0,--cnt;
    build(ro[cnt]);
}
ll query(string s){
    ll ans=0;
    for(int i=1;i<=cnt;++i){
        int u=ro[i];
        for(auto ch:s){
            u=too[u][ch-'0'];
            ans+=f[u];
        }
    }
    return ans;
}
void clear(){
    tot=cnt=0;
    memset(to,0,sizeof(to));
    memset(too,0,sizeof(too));
    memset(te,0,sizeof(te));
    memset(ro,0,sizeof(ro));
    memset(vis,0,sizeof(vis));
    memset(sz,0,sizeof(sz));
    memset(f,0,sizeof(f));
    re.clear();
}
void solve(int _){
    clear();
    int q,l=0;
    cin>>q;
    cout<<"Case #"<<_<<":"<<endl;
    while(q--){
        string cm;
        cin>>cm;
        int cs=cm.size()-1;
        if(cm[0]=='+'){
            cm=cm.substr(1);
            cm=cm.substr(l%cs)+cm.substr(0,l%cs);
            insert(cm);
        }else{
            cm=cm.substr(1);
            cm=cm.substr(l%cs)+cm.substr(0,l%cs);
            cout<<(l=query(cm))<<endl;
        }
    }
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--) solve(++__);
    return 0;
}