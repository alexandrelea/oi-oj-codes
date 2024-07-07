#include <bits/stdc++.h>
using namespace std;
int n,chcn[2];
string s,t;
queue<string> que;
map<string,int> sS;
int main(){
    cin>>n>>s>>t;
    s=" "+s+"..",t=" "+t+"..";
    que.push(s),sS[s]=0;
    while(!que.empty()){
        string stat=que.front();que.pop();
        if(stat==t){
            cout<<sS[t]<<endl;
            return 0;
        }
        int ep=0;
        for(int i=1;i<=n+1;++i) if(stat[i]=='.'){
            ep=i;
            break;
        }
        for(int i=1;i<=n+1;++i){
            if(stat[i]=='.'||stat[i+1]=='.') continue;
            string nstat=stat;
            nstat[ep]=stat[i],nstat[ep+1]=stat[i+1];
            nstat[i]=stat[ep],nstat[i+1]=stat[ep+1];
            if(sS.count(nstat)) continue;
            sS[nstat]=sS[stat]+1,que.push(nstat);
        }
    }
    cout<<-1<<endl;
    return 0;
}