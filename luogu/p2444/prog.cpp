#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const static int SIZE=3e5+10,SIGMA=2;
int trans[SIZE][SIGMA],fail[SIZE],ed[SIZE],tot=0,root=0;
void insert(char *s){
    int len=strlen(s),cur=root;
    for(int i=0;i<len;i++){
        if(trans[cur][s[i]-'0']==0) trans[cur][s[i]-'0']=++tot;
        cur=trans[cur][s[i]-'0'];
    }
    ed[cur]=1;
}
void build(){
    queue<int> que;
    for(int i=0;i<SIGMA;i++) if(trans[root][i]) que.push(trans[root][i]);
    while(!que.empty()){
        int cur=que.front();que.pop();
        for(int i=0;i<SIGMA;i++){
            if(trans[cur][i]==0) trans[cur][i]=trans[fail[cur]][i];
            else{
                fail[trans[cur][i]]=trans[fail[cur]][i],que.push(trans[cur][i]); 
                if(ed[trans[fail[cur]][i]]) ed[trans[cur][i]]=1;
            }
        }
    }
}
int vis[SIZE];
bool dfs(int cur){
    if(vis[cur]!=0) return vis[cur]+1;
    vis[cur]=1;
    for(int i=0;i<SIGMA;i++){
        if(!ed[trans[cur][i]]){
            if(dfs(trans[cur][i])) return true;
        }
    }
    vis[cur]=-1;
    return false;
}
int main(){
    int n;
    char str[SIZE];
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%s",str),insert(str);
    build();
    if(dfs(root)) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    return 0;
}