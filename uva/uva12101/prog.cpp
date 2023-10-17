#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
bool isprime[10010];
void eratosthenes(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=10000;i++){
        if(isprime[i]) for(int j=2;j*i<=10000;j++) isprime[j*i]=false;
    }
}
int maintain(int a,int b){
    if(a==b) return 0;
    queue<int> que;
    map<int,int> vis,stp;
    while(!que.empty()) que.pop();
    vis.clear(),stp.clear();
    que.push(a),vis[a]=1,stp[a]=0;
    que.push(b),vis[b]=2,stp[b]=1;
    while(!que.empty()){
        int nw=que.front();que.pop();
        // cout<<nw<<" "<<vis[nw]<<" "<<stp[nw]<<endl;
        string nws=to_string(nw);
        for(int i=0;i<4;i++){
            for(char ch='0';ch<='9';ch++){
                string nxt=nws;
                nxt[i]=ch;
                if(nxt==nws) continue;
                int nx=atoi(nxt.c_str());
                if(!isprime[nx]||nx<1000) continue;
                if(vis.count(nx)){
                    if(vis[nw]+vis[nx]==3) return stp[nx]+stp[nw];
                    else if(vis[nw]==vis[nx]) continue;
                }else{
                    stp[nx]=stp[nw]+1;
                    vis[nx]=vis[nw];
                    que.push(nx);
                }
            }
        }
    }
}
int main(){
    eratosthenes();
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        cout<<maintain(a,b)<<endl;
    }
    return 0;
}