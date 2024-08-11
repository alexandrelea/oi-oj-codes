#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE=1e6+10,SIGMA=30;
int n,fin[SIZE];
int trans[SIZE][SIGMA],fail[SIZE],ans[SIZE],root=1,tot=1;
char strs[210][SIZE];
vector<int> topo;
void insert(char *s,int id){
    int len=strlen(s),cur=root;
    for(int i=0;i<len;i++){
        ans[cur]++;
        if(trans[cur][s[i]-'a']==0) trans[cur][s[i]-'a']=++tot;
        cur=trans[cur][s[i]-'a'];
    }
    ans[cur]++;
    fin[id]=cur;
}
void build(){
    queue<int> que;
    fail[root]=0,que.push(root);
    for(int i=0;i<SIGMA;i++) trans[0][i]=1;
    while(!que.empty()){
        int cur=que.front();que.pop();
        for(int i=0;i<SIGMA;i++){
            if(trans[cur][i]==0) trans[cur][i]=trans[fail[cur]][i];
            else fail[trans[cur][i]]=trans[fail[cur]][i],que.push(trans[cur][i]),topo.push_back(trans[cur][i]);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%s",strs[i]),insert(strs[i],i);
    build();
    reverse(topo.begin(),topo.end());
    for(auto i:topo) ans[fail[i]]+=ans[i];
    for(int i=1;i<=n;i++) cout<<ans[fin[i]]<<endl;
    return 0;
}