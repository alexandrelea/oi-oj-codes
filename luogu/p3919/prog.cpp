// 洛谷 P3919 - 可持久化线段树 1（可持久化数组）
// Code by Alexandre Lea
#include <iostream>
using namespace std;
const int N=1e6+5;
int n,m,a[N],tree[N<<5],ch[N<<5][2],rt[N<<5],tot;
int build(int lf,int rt){
    int u=++tot;
    if(lf==rt) tree[u]=a[lf];
    else{
        int md=lf+((rt-lf)>>1);
        ch[u][0]=build(lf,md);
        ch[u][1]=build(md+1,rt);
        tree[u]=tree[ch[u][0]]+tree[ch[u][1]];
    }
    return u;
}
int change(int e,int lf,int rt,int ps,int vl){
    int u=++tot;
    tree[u]=tree[e],ch[u][0]=ch[e][0],ch[u][1]=ch[e][1];
    if(lf==rt) tree[u]=vl;
    else{
        int md=lf+((rt-lf)>>1);
        if(ps<=md) ch[u][0]=change(ch[e][0],lf,md,ps,vl);
        else ch[u][1]=change(ch[e][1],md+1,rt,ps,vl);
        tree[u]=tree[ch[u][0]]+tree[ch[u][1]];
    }
    return u;
}
int get(int e,int lf,int rt,int ps){
    if(lf==rt) return tree[e];
    int md=lf+((rt-lf)>>1);
    if(ps<=md) return get(ch[e][0],lf,md,ps);
    else return get(ch[e][1],md+1,rt,ps);
}
int main(){
    ios::sync_with_stdio(false);
    int t=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    rt[0]=build(1,n);
    while(m--){
        int v,o,l,e;
        cin>>v>>o>>l;
        if(o==1){
            cin>>e;
            rt[++t]=change(rt[v],1,n,l,e);
        }else{
            cout<<get(rt[v],1,n,l)<<endl;
            rt[t+1]=rt[v],++t;
        }
    }
    return 0;
}