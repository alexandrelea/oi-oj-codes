// 洛谷 P4513 - 小白逛公园
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,inf=0x3f3f3f3f;
int n,m,a[N<<4];
struct node{
    int lfm,rtm,mim,sum;
    node(int lfm,int rtm,int mim,int sum):lfm(lfm),rtm(rtm),mim(mim),sum(sum){}
    node():lfm(-inf),rtm(-inf),mim(-inf),sum(0){}
}tree[N];
node operator+(const node &a,const node &b){
    return node(
        max(a.lfm,a.sum+b.lfm),
        max(a.rtm+b.sum,b.rtm),
        max(max(a.mim,b.mim),a.rtm+b.lfm),
        a.sum+b.sum
    );
}
void build(int u,int lf,int rt){
    if(lf==rt) tree[u]=node(a[lf],a[lf],a[lf],a[lf]);
    else{
        int md=lf+((rt-lf)>>1);
        build(u<<1,lf,md);
        build(u<<1|1,md+1,rt);
        tree[u]=tree[u<<1]+tree[u<<1|1];
    }
}
node query(int u,int lf,int rt,int ql,int qr){
    if(ql<=lf&&rt<=qr) return tree[u];
    int md=lf+((rt-lf)>>1);
    node ans;
    if(ql<=md) ans=ans+query(u<<1,lf,md,ql,qr);
    if(md<qr) ans=ans+query(u<<1|1,md+1,rt,ql,qr);
    return ans;
}
void change(int u,int lf,int rt,int ps,int vl){
    if(lf==rt) tree[u]=node(vl,vl,vl,vl);
    else{
        int md=lf+((rt-lf)>>1);
        if(ps<=md) change(u<<1,lf,md,ps,vl);
        else change(u<<1|1,md+1,rt,ps,vl);
        tree[u]=tree[u<<1]+tree[u<<1|1];
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    build(1,1,n);
    while(m--){
        int k,a,b;
        cin>>k>>a>>b;
        if(k==1){
            if(a>b) swap(a,b);
            cout<<query(1,1,n,a,b).mim<<endl;
        }else change(1,1,n,a,b);
    }
    return 0;
}