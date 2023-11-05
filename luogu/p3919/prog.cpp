#include <iostream>
using namespace std;
const int SIZE=1e6+5;
int a[SIZE],n,m,q,rt[SIZE<<5],ch[SIZE<<5][2],val[SIZE<<5],cnt;
void build(int &co,int lf,int rt){
    co=++cnt;
    if(lf==rt) return val[co]=a[lf],void();
    int mi=lf+((rt-lf)>>1);
    build(ch[co][0],lf,mi),build(ch[co][1],mi+1,rt);
}
void modify(int &co,int lf,int rt,int &qu,int mq,int mv){
    co=++cnt;
    ch[co][0]=ch[qu][0],ch[co][1]=ch[qu][1],val[co]=val[qu];
    if(lf==rt) return val[co]=mv,void();
    int mi=lf+((rt-lf)>>1);
    if(mq<=mi) modify(ch[co][0],lf,mi,ch[qu][0],mq,mv);
    else modify(ch[co][1],mi+1,rt,ch[qu][1],mq,mv);
}
int query(int co,int lf,int rt,int qx){
    if(lf==rt) return val[co];
    int mi=lf+((rt-lf)>>1);
    if(qx<=mi) return query(ch[co][0],lf,mi,qx);
    else return query(ch[co][1],mi+1,rt,qx);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(rt[0],1,n);
    for(int i=1;i<=m;i++){
        int hi,opt,x,v;
        cin>>hi>>opt>>x;
        if(opt==1) cin>>v,modify(rt[i],1,n,rt[hi],x,v);
        if(opt==2) cout<<query(rt[hi],1,n,x)<<endl,rt[i]=rt[hi];
    }
    return 0;
}