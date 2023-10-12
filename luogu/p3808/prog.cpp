#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int SIGMA=256,SIZE=2e6+10;
int trans[SIZE][SIGMA],fail[SIZE],ed[SIZE],tot=1;
void insert(char *c){
    int len=strlen(c),cur=1;
    for(int i=0;i<len;i++){
        if(trans[cur][c[i]]==0) trans[cur][c[i]]=++tot;
        cur=trans[cur][c[i]];
    }
    ed[cur]++;
}
void build(){
    queue<int> que;
    for(int i=0;i<SIGMA;i++) trans[0][i]=1;
    que.push(1),fail[1]=0;
    while(!que.empty()){
        int cur=que.front();que.pop();
        for(int i=0;i<SIGMA;i++){
            if(trans[cur][i]==0) trans[cur][i]=trans[fail[cur]][i];
            else fail[trans[cur][i]]=trans[fail[cur]][i],que.push(trans[cur][i]);
        }
    }
}
int acquery(char *s){
    int len=strlen(s),cur=1,ans=0;
    for(int i=0;i<len;i++){
        cur=trans[cur][s[i]];
        for(int now=cur;now!=0&&ed[now]!=-1;now=fail[now]){
            ans+=ed[now];
            ed[now]=-1;
        }
    }
    return ans;
}
int main(){
    int n;
    char str[SIZE];
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        insert(str);
    }
    build();
    scanf("%s",str);
    cout<<acquery(str)<<endl;
    return 0;
}