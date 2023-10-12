#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int SIZE=1e6+10,SIGMA=26;
int n,k,buc[SIZE],tot,ed[SIZE],trans[SIZE][SIGMA],fail[SIZE];
vector<int> edge[SIZE];
void insert(string str,int id){
    int co=0;
    for(char ch:str){
        if(trans[co][ch-'a']==0) trans[co][ch-'a']=++tot;
        co=trans[co][ch-'a'];
    }
    ed[id]=co;
}
void build(){
    queue<int> que;
    for(int i=0;i<SIGMA;i++) if(trans[0][i]!=0) que.push(trans[0][i]);
    while(!que.empty()){
        int co=que.front();que.pop();
        for(int i=0;i<SIGMA;i++)
            if(trans[co][i]) fail[trans[co][i]]=trans[fail[co]][i],que.push(trans[co][i]);
            else trans[co][i]=trans[fail[co]][i];
        edge[fail[co]].push_back(co);
    }
}
int cnt=0,dfn[SIZE],sz[SIZE],c[SIZE];
void add(int x,int v){
    while(x<=tot) c[x]+=v,x+=x&-x;
}
int query(int x){
    int s=0;
    while(x) s+=c[x],x-=x&-x;
    return s;
}
void dfs(int co){
    dfn[co]=cnt++,sz[co]=1;
    for(int ni:edge[co]) dfs(ni),sz[co]+=sz[ni];
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        string st;
        cin>>st;
        insert(st,i);
    }
    build(),dfs(0);
    for(int i=1;i<=k;i++){
        int id=ed[i];
        add(dfn[id],1);
        add(dfn[id]+sz[id],-1);
        buc[i]=1;
    }
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='?'){
            string s;
            cin>>s;
            int co=0;
            long long ans=0;
            for(char ch:s){
                co=trans[co][ch-'a'];
                ans+=query(dfn[co]);
            }
            cout<<ans<<endl;
        }else{
            int id;
            cin>>id;
            if(c=='-'){
                if(!buc[id]) continue;
                buc[id]=0,id=ed[id];
                add(dfn[id],-1);
                add(dfn[id]+sz[id],1);
            }else{
                if(buc[id]) continue;
                buc[id]=1,id=ed[id];
                add(dfn[id],1);
                add(dfn[id]+sz[id],-1);
            }
        }
    }
    return 0;
}
