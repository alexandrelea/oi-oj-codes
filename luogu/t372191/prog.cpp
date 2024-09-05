// 洛谷 - T372191 小猫吃火龙果
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2'0000'5;
typedef short sht;
int n,q;
sht iis[N],e[N*4][3][3][3][3],f[N*4][3],p[N*4][3],t[N*4][3];
// 0 eat 1,1 eat 2,2 eat 0
// hand eat seq=>hand, seq eat hand=>seq
int eatq(int p,int q){
    if(q==(p+1)%3||q==p) return p;
    else return q; 
}
int trans(int x,int i0,int i1,int i2){
    if(x==0) return i0;
    else if(x==1) return i1;
    else return i2;
}
void build(int nw,int lf,int rt){
    for(sht i=0;i<3;++i) p[nw][i]=i;
    if(lf==rt){
        sht x=iis[lf];
        for(sht i=0;i<3;++i) for(sht j=0;j<3;++j) for(sht k=0;k<3;++k) if(k!=i&&k!=j) for(sht l=0;l<3;++l){
            e[nw][i][j][k][l]=eatq(trans(l,i,j,k),trans(x,i,j,k));
        }
        for(int i=0;i<3;++i) f[nw][i]=e[nw][0][1][2][i];
        return;
    }else{
        int mi=lf+((rt-lf)>>1);
        build(nw<<1,lf,mi),build(nw<<1|1,mi+1,rt);
        for(sht i=0;i<3;++i) for(sht j=0;j<3;++j) if(j!=i) for(sht k=0;k<3;++k) if(k!=i&&k!=j) for(sht l=0;l<3;++l){
            e[nw][i][j][k][l]=e[nw<<1|1][i][j][k][e[nw<<1][i][j][k][l]];
            f[nw][l]=f[nw<<1|1][f[nw<<1][l]];
        }
    }
}
void maintain(int nw){
    if(t[nw][0]==0&&t[nw][1]==0&&t[nw][2]==0) return;
    int nlc=nw<<1,nrc=nw<<1|1;
    for(int i=0;i<3;++i) p[nlc][i]=p[nrc][i]=t[nw][i],t[nw][i]=0;
    for(int i=0;i<3;++i) f[nw][i]=e[nw][p[nw][0]][p[nw][1]][p[nw][2]][i];
}
void consolid(int nw){
    for(int i=0;i<3;++i) f[nw][i]=f[nw<<1|1][f[nw<<1][i]];
}
sht ask(int nw,int lf,int rt,int lq,int rq,sht lv){
    if(lq<=lf&&rt<=rq) return f[nw][lv];
    int mi=lf+((rt-lf)>>1);
    maintain(nw);
    sht ans=0;
    if(lq<=mi){
        ans=ask(nw<<1,lf,mi,lq,rq,lv);
        if(mi<rq) ans=ask(nw<<1|1,mi+1,rt,lq,rq,ans);
    }else if(mi<rq) ans=ask(nw<<1|1,mi+1,rt,lq,rq,lv);
    return ans;
}
void che(int nw,int lf,int rt,int lh,int rh,sht x,sht y){
    if(lh<=lf&&rt<=rh){
        swap(p[nw][x],p[nw][y]);
        for(int i=0;i<3;++i) t[nw][i]=p[nw][i];
        for(int i=0;i<3;++i) f[nw][i]=e[nw][p[nw][0]][p[nw][1]][p[nw][2]][i];
        return;
    }
    maintain(nw);
    int mi=lf+((rt-lf)>>1);
    if(lh<=mi) che(nw<<1,lf,mi,lh,rh,x,y);
    if(mi<rh) che(nw<<1|1,mi+1,rt,lh,rh,x,y);
    consolid(nw);
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        char ch;
        cin>>ch;
        iis[i]=ch-'A';
    }
    build(1,1,n);
    while(q--){
        int op,l,r;
        sht x,y;
        char ch;
        cin>>op>>l>>r>>ch,x=ch-'A';
        if(op==1) cout<<(char)('A'+ask(1,1,n,l,r,x))<<endl;
        else cin>>ch,y=ch-'A',che(1,1,n,l,r,x,y);
    }
    return 0;
}