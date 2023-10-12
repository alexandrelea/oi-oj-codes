#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
struct ACAM{
    const static int SIGMA=26;
    vector<vector<int>> trans,bktr;
    vector<int> fail,ed;
    bool changed,got;
    int tot,root=0,tans=0;
    ACAM(int ze){
        fail=vector<int>((ze+1)*SIGMA,0),ed=vector<int>((ze+1)*SIGMA);
        //fail.resize(ze+1),ed.resize(ze+1);
        bktr=trans=vector<vector<int>>((ze+1)*SIGMA,vector<int>(SIGMA,0));
        // trans.resize(ze+1,vector<int>(SIGMA));
        root=tot=0,changed=got=false;
    }
    void insert(string st){
        if(!changed) trans=bktr;
        int co=root;
        for(auto ch:st){
            if(trans[co][ch-'a']==0) trans[co][ch-'a']=(++tot);
            co=trans[co][ch-'a'];
        }
        ed[co]++,changed=true,got=false;
    }
    void build(){
        if(!changed) return;
        changed=false,got=false;
        bktr=trans,fail=vector<int>(fail.size(),0);
        queue<int> que;
        // for(int i=0;i<SIGMA;i++) trans[0][i]=1;
        // que.push(1),fail[1]=0;
        for(int i=0;i<SIGMA;i++) if(trans[root][i]!=0) que.push(trans[root][i]);
        while(!que.empty()){
            int co=que.front();que.pop();
            for(int i=0;i<SIGMA;i++){
                if(trans[co][i]) fail[trans[co][i]]=trans[fail[co]][i],que.push(trans[co][i]);
                else trans[co][i]=trans[fail[co]][i];
            }
        }
    }
    int query(string st){
        if(got) return tans;
        got=true;
        int co=root,ans=0;
        for(auto ch:st){
            co=trans[co][ch-'a'];
            for(int nw=co;nw!=0;nw=fail[nw]) ans+=ed[nw];
        }
        return tans=ans;
    }
}inserted[13]={ACAM(2),ACAM(4),ACAM(8),ACAM(16),ACAM(32),ACAM(64),ACAM(128),ACAM(256),ACAM(512),ACAM(1024),ACAM(2048),ACAM(4096),ACAM(8192)},
deleted[13]={ACAM(2),ACAM(4),ACAM(8),ACAM(16),ACAM(32),ACAM(64),ACAM(128),ACAM(256),ACAM(512),ACAM(1024),ACAM(2048),ACAM(4096),ACAM(8192)};
int main(){
    int m,t;
    string st;
    cin>>m;
    while(m--){
        cin>>t>>st;
        if(t==1||t==2){
            int lon=log2(st.length());
            if(t==1) inserted[lon].insert(st);
            else deleted[lon].insert(st);
        }else{
            int ins=0,del=0;
            for(int i=0;i<13;i++){
                inserted[i].build();
                deleted[i].build();
                ins+=inserted[i].query(st);
                del+=deleted[i].query(st);
            }
            cout<<ins-del<<endl<<flush;
        }
    }
    return 0;
}