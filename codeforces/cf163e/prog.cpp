#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int SIZE=1e6+10,SIGMA=26;
int k,n;
char str[1500][SIZE/10+9];
bool inn[1500];
int ats[1500];
int trans[SIZE][SIGMA],ed[SIZE],fail[SIZE],tot=1;
vector<int> topo;
void insert(char *s,int &at){
    int len=strlen(s),cur=1;
    for(int i=0;i<len;i++){
        ed[cur]++;
        if(trans[cur][s[i]-'a']==0) trans[cur][s[i]-'a']=++tot;
        cur=trans[cur][s[i]-'a'];
    }
    ed[cur]++;
    at=cur;
}
void build(){
    queue<int> que;
    que.push(1),fail[1]=0;
    for(int i=0;i<SIGMA;i++) trans[0][i]=1;
    while(!que.empty()){
        int cur=que.front();que.pop();
        for(int i=0;i<SIGMA;i++){
            if(trans[cur][i]==0) trans[cur][i]=trans[fail[cur]][i];
            else fail[trans[cur][i]]=trans[fail[cur]][i],que.push(trans[cur][i]);
        }
    }
}
int query(char *s){
    int len=strlen(s),cur=1,ans=0;
    for(int i=0;i<len;i++){
        cur=trans[cur][s[i]-'a'];
        for(int now=cur;now!=0;now=fail[now]) ans+=ed[now];
    }
    return ans;
}
int main(){
    scanf("%d %d",&k,&n);
    for(int i=1;i<=n;i++) scanf("%s",str[i]),insert(str[i],ats[i]),inn[i]=true;
    build();
    while(k--){
        scanf("%s",str[0]);
        if(str[0][0]=='?'){
            printf("%d\n",query(str[0]+1));
        }else if(str[0][0]=='+'||str[0][0]=='-'){
            int m=stoi(str[0]+1);
            if(str[0][0]=='+'&&!inn[m]) ed[ats[m]]++,inn[m]=true;
            else if(str[0][0]=='-'&&inn[m]) ed[ats[m]]--,inn[m]=false;
        }
    }
    return 0;
}
