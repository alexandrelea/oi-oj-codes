#include<bits/stdc++.h>
#define int __int128_t
using namespace std;
const int SIZE=3e5+10,INF=0x3f3f3f3f;
int n,m,a[SIZE],yes;
int abs(int x){
    return x<0?-x:x;
}
struct data{
    int hcf,minv,maxv,sumv,sqmv;
    data(int hcf=0,int minv=+INF,int maxv=-INF,int sumv=0,int sqmv=0):hcf(hcf),minv(minv),maxv(maxv),sumv(sumv),sqmv(sqmv){}
    data operator+(const data &rhs)const{
        return data(__gcd(hcf,rhs.hcf),min(minv,rhs.minv),max(maxv,rhs.maxv),sumv+rhs.sumv,sqmv+rhs.sqmv);
    }
}tree[SIZE*4];
void build(int co,int lf,int rt){
    if(lf==rt){
        tree[co]=data(abs(a[lf]-a[lf-1]),a[lf],a[lf],a[lf],a[lf]*a[lf]);
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(co*2,lf,mi),build(co*2+1,mi+1,rt);
    tree[co]=tree[co*2]+tree[co*2+1];
}
void modify(int co,int lf,int rt,int mx,int mv){
    if(lf==rt){
        tree[co]=data(abs(mv-a[lf-1]),mv,mv,mv,mv*mv);
        return;
    }
    int mi=lf+(rt-lf)/2;
    if(mx<=mi) modify(co*2,lf,mi,mx,mv);
    else modify(co*2+1,mi+1,rt,mx,mv);
    tree[co]=tree[co*2]+tree[co*2+1];
}
data query(int co,int lf,int rt,int ql,int qr){
    if(ql<=lf&&rt<=qr) return tree[co];
    int mi=lf+(rt-lf)/2;
    data qans=data();
    if(ql<=mi) qans=qans+query(co*2,lf,mi,ql,qr);
    if(mi<qr) qans=qans+query(co*2+1,mi+1,rt,ql,qr);
    return qans;
}
long long c;
signed main(){
    ios::sync_with_stdio(false);
    cin>>c,n=c,cin>>c,m=c;
    for(int i=1;i<=n;i++) cin>>c,a[i]=c;
    build(1,1,n);
    while(m--){
        int op,x,y,l,r,k;
        cin>>c,op=c;
        if(op==1){
            cin>>c,x=c,cin>>c,y=c;
            x^=yes,y^=yes;
            modify(1,1,n,x,y);
            a[x]=y;
            if(x+1<=n) modify(1,1,n,x+1,a[x+1]);
        }else{
            cin>>c,l=c,cin>>c,r=c,cin>>c,k=c;
            l^=yes,r^=yes,k^=yes;
            if(l==r){
                cout<<"Yes"<<endl;
                ++yes;
                continue;
            }
            data got1=query(1,1,n,l,r),got2=query(1,1,n,l+1,r);
            int minv=got1.minv,maxv=got1.maxv,hcfv=got2.hcf,sqmv=got1.sqmv;
            if((maxv-minv)==k*(r-l)&&hcfv==k&&got1.sumv*2==(minv+maxv)*(r-l+1)&&sqmv==((r-l+1)*minv*minv+minv*k*(r-l+1)*(r-l)+(r-l+1)*(r-l)*(2*(r-l+1)-1)*k*k/6)) cout<<"Yes"<<endl,++yes;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}