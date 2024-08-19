#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIGMA=30,SIZE=11000;
int trans[SIZE][SIGMA],fail[SIZE],ed[SIZE],tot=1;
pair<int,int> ans[170];
void insert(char *c,int di){
    int len=strlen(c),cur=1;
    for(int i=0;i<len;i++){
        if(trans[cur][c[i]-'a']==0) trans[cur][c[i]-'a']=++tot;
        cur=trans[cur][c[i]-'a'];
    }
    ed[cur]=di;
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
void acquery(char *s){
    int len=strlen(s),cur=1;
    for(int i=0;i<len;i++){
        cur=trans[cur][s[i]-'a'];
        for(int now=cur;now!=0&&ed[now]!=-1;now=fail[now]){
            ans[ed[now]].first++;
        }
    }
}
int main(){
    int n;
    char str[170][SIZE];
    while(cin>>n&&n!=0){
        memset(trans,0,sizeof trans);
        memset(fail,0,sizeof fail);
        memset(ed,0,sizeof ed);
        memset(str,0,sizeof str);
        tot=1;
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]);
            insert(str[i],i);
            ans[i].first=0,ans[i].second=i;
        }
        build();
        char s[(int)1e6+10];
        scanf("%s",s);
        acquery(s);
        sort(ans+1,ans+n+1,[](pair<int,int> a,pair<int,int> b)->bool {
            return a.first!=b.first?a.first>b.first:a.second<b.second;
        });
        cout<<ans[1].first<<endl<<str[ans[1].second]<<endl;
        for(int i=2;i<=n;i++) if(ans[i].first==ans[i-1].first) cout<<str[ans[i].second]<<endl; else break;
    }
    return 0;
}