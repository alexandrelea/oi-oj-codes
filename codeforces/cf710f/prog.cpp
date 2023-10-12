#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int SIGMA=30,SIZE=2e6+10;
struct ahocorasick{
    int trans[SIZE][SIGMA],fail[SIZE],ed[SIZE],tot=1,bcktrans[SIZE][SIGMA];
    bool changed=false;
    ahocorasick(){
        memset(trans,0,sizeof trans);
        memset(fail,0,sizeof fail);
        memset(ed,0,sizeof ed);
        tot=1;
    }
    void insert(char *c){
        changed=true;
        int len=strlen(c),cur=1;
        for(int i=0;i<len;i++){
            if(trans[cur][c[i]-'a']==0) trans[cur][c[i]-'a']=++tot;
            cur=trans[cur][c[i]-'a'];
        }
        ed[cur]++;
    }
    void build(){
        if(!changed) return;
        changed=false;
        memcpy(bcktrans,trans,sizeof trans);
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
            cur=trans[cur][s[i]-'a'];
            for(int now=cur;now!=0;now=fail[now]) ans+=ed[now];
        }
        return ans;
    }
}inserted[18],deleted[18];
int main(){
    int n;
    int o;
    char str[SIZE];
    cin>>n;
    while(n--){
        scanf("%d %s",&o,str);
        int lln=log2(strlen(str));
        if(o==1) inserted[lln].insert(str);
        if(o==2) deleted[lln].insert(str);
        if(o==3){
            int ins=0,del=0;
            for(int i=0;i<18;i++) inserted[i].build(),ins+=inserted[i].acquery(str);
            for(int i=0;i<18;i++) deleted[i].build(),del+=deleted[i].acquery(str);
            cout<<ins-del<<endl<<flush;
        }
    }
    return 0;
}