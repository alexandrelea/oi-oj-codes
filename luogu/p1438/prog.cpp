#include <iostream>
#define int long long
using namespace std;
const int SIZE=1e5+10;
int n,m,a[SIZE],d[SIZE];
int rt,ch[SIZE*4][2],tag[SIZE*4],sum[SIZE*4],cnt;
void pushup(int co){
    sum[co]=sum[ch[co][0]]+sum[ch[co][1]];
}
void pushdown(int co,int lf,int rt){
    if(tag[co]==0) return;
    int mi=lf+(rt-lf)/2;
    tag[ch[co][0]]+=tag[co],sum[ch[co][0]]+=tag[co]*(mi-lf+1);
    tag[ch[co][1]]+=tag[co],sum[ch[co][1]]+=tag[co]*(rt-mi);
    tag[co]=0;
}
void build(int &co,int lf,int rt){
    if(co==0) co=++cnt;
    if(lf==rt) return sum[co]=d[lf],void();
    int mi=lf+(rt-lf)/2;
    build(ch[co][0],lf,mi),build(ch[co][1],mi+1,rt);
    pushup(co);
}
void modify(int co,int lf,int rt,int ml,int mr,int mv){
    if(ml<=lf&&rt<=mr)
        return sum[co]+=(rt-lf+1)*mv,tag[co]+=mv,void();
    pushdown(co,lf,rt);
    int mi=lf+(rt-lf)/2;
    if(ml<=mi) modify(ch[co][0],lf,mi,ml,mr,mv);
    if(mi<mr) modify(ch[co][1],mi+1,rt,ml,mr,mv);
    pushup(co);
}
int query(int co,int lf,int rt,int ql,int qr){
    if(ql<=lf&&rt<=qr) return sum[co];
    pushdown(co,lf,rt);
    int mi=lf+(rt-lf)/2,qans=0;
    if(ql<=mi) qans+=query(ch[co][0],lf,mi,ql,qr);
    if(mi<qr) qans+=query(ch[co][1],mi+1,rt,ql,qr);
    return qans;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++) d[i]=a[i]-a[i-1];
    build(rt,1,n);
    while(m--){
        int o,l,r,k,d,p;
        cin>>o;
        if(o==1){
            cin>>l>>r>>k>>d;
            modify(rt,1,n,l,l,k);
            if(l<r) modify(1,1,n,l+1,r,d);
            if(r<n) modify(rt,1,n,r+1,r+1,-(k+(r-l)*d));
        }else{
            cin>>p;
            cout<<query(rt,1,n,1,p)<<endl;
        }
    }
    return 0;
}