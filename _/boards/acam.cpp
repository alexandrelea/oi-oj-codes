#include <bits/stdc++.h>
using namespace std;
struct ACAM{
    const static int SIGMA=26,SIZE=1e5+5;
    int cnt,rts,tr[SIZE][SIGMA],tr2[SIZE][SIGMA];
    int rt[SIZE],fail[SIZE],val[SIZE],siz[SIZE];
    long long tmp[SIZE];
    void insert(string s,int &rt){ // 普通的开点加边
        if(rt==0) rt=++cnt;
        int co=rt;
        for(auto ch:s){
            if(tr[co][ch-'a']==0) tr[co][ch-'a']=++cnt;
            co=tr[co][ch-'a'];
        }
        val[co]++;
    }
    void build(int rt){
        queue<int> que;
        fail[rt]=rt;
        for(int i=0;i<SIGMA;i++){
            if(tr[rt][i]!=0) tr2[rt][i]=tr[rt][i],fail[tr[rt][i]]=rt,que.push(tr[rt][i]);
            else tr2[rt][i]=rt;
        }
        while(!que.empty()){
            int co=que.front();que.pop();
            tmp[co]=val[co]+tmp[fail[co]]; // 这一步匹配的 与 之前匹配的 之和 往后累加
            for(int i=0;i<SIGMA;i++)
                if(tr[co][i]) tr2[co][i]=tr[co][i],fail[tr[co][i]]=tr2[fail[co]][i],que.push(tr[co][i]);
                else tr2[co][i]=tr2[fail[co]][i];
        }
    }
    int merge(int x,int y){
        if(x==0||y==0) return x+y;
        val[x]+=val[y]; // 应当是出现次数
        for(int i=0;i<SIGMA;i++) tr[x][i]=merge(tr[x][i],tr[y][i]);
        return x;
    }
    void insert(string st){
        siz[++rts]=1;
        insert(st,rt[rts]); // 新开一条边
        while(siz[rts-1]==siz[rts]) siz[rts-1]+=siz[rts],rt[rts-1]=merge(rt[rts-1],rt[rts]),rt[rts]=0,rts--; // 把这一条边并进ACAM里面
        build(rt[rts]);
    }
    long long query(string st){
        long long ans=0;
        for(int i=1;i<=rts;i++){
            int co=rt[i];
            for(auto ch:st){
                co=tr2[co][ch-'a'];
                ans+=tmp[co];
            }
        }
        return ans;
    }
};