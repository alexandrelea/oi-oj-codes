// 洛谷 p1972 - HH的项链
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],eh[N],ans[N];
struct query{
    int lf,rt,id;
    query():lf(0),rt(0),id(0){}
    query(int l,int r,int i):lf(l),rt(r),id(i){}
}Q[N];
void add(int x,int d){
    for(;x<=n;x+=x&(-x)) eh[x]+=d;
}
int sum(int x){
    int ans=0;
    for(;x>0;x-=x&(-x)) ans+=eh[x];
    return ans;
}
int ex[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;++i) cin>>Q[i].lf>>Q[i].rt,Q[i].id=i;
    sort(Q+1,Q+m+1,[](query a,query b)->bool {return a.rt<b.rt;});
    int tot=1;
    for(int i=1;i<=n;++i){
        if(ex[a[i]]==0) ex[a[i]]=i,add(i,1);
        else add(ex[a[i]],-1),ex[a[i]]=i,add(i,1);
        while(tot<=m) if(Q[tot].rt==i) ans[Q[tot].id]=sum(Q[tot].rt)-sum(Q[tot].lf-1),++tot; else break;
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<endl;
    return 0;
}
//