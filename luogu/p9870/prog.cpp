#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,INF=0x3f3f3f3f;
int c,n,m,q,x[N],y[N],mxx[N*4],mxy[N*4],mnx[N*4],mny[N*4];
int cxp[N],cxv[N],cxl[N],cyp[N],cyv[N],cyl[N];  
int sgn(int x){
    return x<0?-1:x==0?0:1;
}
void buildx(int co,int lf,int rt){
    if(lf==rt){
        mxx[co]=mnx[co]=x[lf];
        return;
    }
    int mi=lf+(rt-lf)/2;
    buildx(co*2,lf,mi);
    buildx(co*2+1,mi+1,rt);
    mxx[co]=max(mxx[co*2],mxx[co*2+1]);
    mnx[co]=min(mxx[co*2],mxx[co*2+1]);
}
void buildy(int co,int lf,int rt){
    if(lf==rt){
        mxy[co]=mny[co]=y[lf];
        return;
    }
    int mi=lf+(rt-lf)/2;
    buildy(co*2,lf,mi);
    buildy(co*2+1,mi+1,rt);
    mxy[co]=max(mxy[co*2],mxy[co*2+1]);
    mny[co]=min(mxy[co*2],mxy[co*2+1]);
}
void modifyx(int co,int lf,int rt,int po,int vl){
    if(lf==rt){
        mxx[co]=mnx[co]=vl;
        return;
    }
    int mi=lf+(rt-lf)/2;
    if(po<=mi) modifyx(co*2,lf,mi,po,vl);
    else modifyx(co*2+1,mi+1,rt,po,vl);
    mxy[co]=max(mxy[co*2],mxy[co*2+1]);
    mny[co]=min(mxy[co*2],mxy[co*2+1]);
}
void modifyy(int co,int lf,int rt,int po,int vl){
    if(lf==rt){
        mxy[co]=mny[co]=vl;
        return;
    }
    int mi=lf+(rt-lf)/2;
    if(po<=mi) modifyy(co*2,lf,mi,po,vl);
    else modifyy(co*2+1,mi+1,rt,po,vl);
    mxy[co]=max(mxy[co*2],mxy[co*2+1]);
    mny[co]=min(mxy[co*2],mxy[co*2+1]);
}
int querymnx(int co,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return mnx[co];
    int mi=lf+(rt-lf)/2,ans=INF;
    if(qul<=mi) ans=min(ans,querymnx(co*2,lf,mi,qul,qur));
    if(mi<qur) ans=min(ans,querymnx(co*2+1,mi+1,rt,qul,qur));
    return ans;
}
int querymxx(int co,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return mxx[co];
    int mi=lf+(rt-lf)/2,ans=-INF;
    if(qul<=mi) ans=max(ans,querymxx(co*2,lf,mi,qul,qur));
    if(mi<qur) ans=max(ans,querymxx(co*2+1,mi+1,rt,qul,qur));
    return ans;
}
int querymny(int co,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return mny[co];
    int mi=lf+(rt-lf)/2,ans=INF;
    if(qul<=mi) ans=min(ans,querymny(co*2,lf,mi,qul,qur));
    if(mi<qur) ans=min(ans,querymny(co*2+1,mi+1,rt,qul,qur));
    return ans;
}
int querymxy(int co,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return mxy[co];
    int mi=lf+(rt-lf)/2,ans=-INF;
    if(qul<=mi) ans=max(ans,querymxy(co*2,lf,mi,qul,qur));
    if(mi<qur) ans=max(ans,querymxy(co*2+1,mi+1,rt,qul,qur));
    return ans;
}
void solve(){
    if(sgn(x[1]-y[1])!=sgn(x[n]-y[m])) return cout<<0,void();
    int sg=sgn(x[1]-y[1]);
    for(int i=1,j=1;i!=n||j!=m;){
        if(sgn(x[i+1]-y[j+1])==sg&&i+1<=n&&j+1<=m) i++,j++;
        else if(sgn(x[i+1]-y[j])==sg&&i+1<=n) i++;
        else if(sgn(x[i]-y[j+1])==sg&&j+1<=m) j++;
        else{
            int ss0=sgn(x[i+1]-y[j]),ss1=sgn(x[i]-y[j+1]);
            if(((ss0==-1&&querymxy(1,1,m,1,j)>x[i+1])||(ss0==1&&querymny(1,1,m,1,j)<x[i+1]))&&i+1<=n) ++i;
            else if(((ss1==-1&&querymxx(1,1,n,1,i)>y[j+1])||(ss0==1&&querymnx(1,1,n,1,i)<y[j+1]))&&j+1<=n) ++j;
            else return cout<<0,void();
        }
    }
    cout<<1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=m;++i) cin>>y[i];
    buildx(1,1,n),buildy(1,1,m);
    solve();
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;++i){
            cin>>cxp[i]>>cxv[i];
            cxl[i]=x[cxp[i]];
            x[cxp[i]]=cxv[i];
            modifyx(1,1,n,cxp[i],cxv[i]);
        }
        for(int i=1;i<=ky;++i){
            cin>>cyp[i]>>cyv[i];
            cyl[i]=y[cyp[i]];
            y[cyp[i]]=cyv[i];
            modifyy(1,1,n,cyp[i],cyv[i]);
        }
        solve();
        for(int i=1;i<=kx;++i) modifyx(1,1,n,cxp[i],cxl[i]),x[cxp[i]]=cxl[i];
        for(int i=1;i<=ky;++i) modifyx(1,1,n,cyp[i],cyl[i]),y[cyp[i]]=cyl[i];
    }
    return 0;
}