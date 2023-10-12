#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
const int SIZE=6e5+10;
struct ACAM{
    const static int SIGMA=26;
    int cnt,rts,trans[SIZE][SIGMA],tarns[SIZE][SIGMA];
    int root[SIZE],fail[SIZE],val[SIZE],siz[SIZE];
    long long tmp[SIZE];
    void insert(string s,int &root){
        if(root==0) root=++cnt;
        int co=root;
        for(auto ch:s){
            if(trans[co][ch-'a']==0) trans[co][ch-'a']=++cnt;
            co=trans[co][ch-'a'];
        }
        val[co]++;
    }
    void build(int root){
        queue<int> que;
        fail[root]=root;
        for(int i=0;i<SIGMA;i++){
            if(trans[root][i]!=0) tarns[root][i]=trans[root][i],fail[trans[root][i]]=root,que.push(trans[root][i]);
            else tarns[root][i]=root;
        }
        while(!que.empty()){
            int co=que.front();que.pop();
            tmp[co]=val[co]+tmp[fail[co]];
            for(int i=0;i<SIGMA;i++)
                if(trans[co][i]) tarns[co][i]=trans[co][i],fail[trans[co][i]]=tarns[fail[co]][i],que.push(trans[co][i]);
                else tarns[co][i]=tarns[fail[co]][i];
        }
    }
    int merge(int x,int y){
        if(x==0||y==0) return x+y;
        val[x]+=val[y];
        for(int i=0;i<SIGMA;i++) trans[x][i]=merge(trans[x][i],trans[y][i]);
        return x;
    }
    void insert(string st){
        siz[++rts]=1;
        insert(st,root[rts]);
        while(siz[rts-1]==siz[rts]) siz[rts-1]+=siz[rts],root[rts-1]=merge(root[rts-1],root[rts]),root[rts]=0,rts--;
        build(root[rts]);
    }
    long long query(string st){
        long long ans=0;
        for(int i=1;i<=rts;i++){
            int co=root[i];
            for(auto ch:st){
                co=tarns[co][ch-'a'];
                ans+=tmp[co];
            }
        }
        return ans;
    }
}in,de;
int main(){
    int m,t;
    string st;
    cin>>m;
    while(m--){
        cin>>t>>st;
        if(t==1) in.insert(st);
        if(t==2) de.insert(st);
        if(t==3) cout<<in.query(st)-de.query(st)<<endl<<flush;
    }
    return 0;
}