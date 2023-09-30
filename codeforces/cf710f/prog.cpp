#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int SIGMA=30,SIZE=2e6+10;
struct ahocorasick{
    int trans[SIZE][SIGMA],fail[SIZE],ed[SIZE],tot=1,bcktrans[SIZE][SIGMA];
    ahocorasick(){
        memset(trans,0,sizeof trans);
        memset(fail,0,sizeof fail);
        memset(ed,0,sizeof ed);
        tot=1;
    }
    void insert(char *c){
        int len=strlen(c),cur=1;
        for(int i=0;i<len;i++){
            if(trans[cur][c[i]-'a']==0) trans[cur][c[i]-'a']=++tot;
            cur=trans[cur][c[i]-'a'];
        }
        ed[cur]++;
    }
    void build(){
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
        memcpy(trans,bcktrans,sizeof trans);
        memset(fail,0,sizeof fail);
        return ans;
    }
}inserted,deleted;
int main(){
    int n;
    int o;
    char str[SIZE];
    cin>>n;
    while(n--){
        scanf("%d %s",&o,str);
        if(o==1) inserted.insert(str);
        if(o==2) deleted.insert(str);
        if(o==3){
            inserted.build();
            deleted.build();
            cout<<inserted.acquery(str)-deleted.acquery(str)<<endl<<flush;
        }
    }
    return 0;
}