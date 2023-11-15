#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10,INF=0x3f3f3f3f;
struct dat{
    int sum,lfms,rtms,mims;
    dat(int sum=0,int lfms=-INF,int rtms=-INF,int mims=-INF):sum(sum),lfms(lfms),rtms(rtms),mims(mims){}
    dat operator+(const dat &rhs)const{
        return dat(sum+rhs.sum,max(lfms,sum+rhs.lfms),max(rhs.rtms,rtms+rhs.sum),max(rtms+rhs.lfms,max(mims,rhs.mims)));
    }
};
int n,a[N],m;
struct omg{
    dat dta;
    omg *ch[2];
    omg(dat dta=dat(),omg *lfch=nullptr,omg *rtch=nullptr):dta(dta){
        ch[0]=lfch,ch[1]=rtch;
    }
}*root;
void build(omg *&wtf,int lf,int rt){
    wtf=new omg;
    if(lf==rt){
        wtf->dta=dat(a[lf],a[lf],a[lf],a[lf]);
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(wtf->ch[0],lf,mi);
    build(wtf->ch[1],mi+1,rt);
    wtf->dta=wtf->ch[0]->dta+wtf->ch[1]->dta;
}
dat query(omg *wtf,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return wtf->dta;
    int mi=lf+(rt-lf)/2;
    dat ans=dat();
    if(qul<=mi) ans=ans+query(wtf->ch[0],lf,mi,qul,qur);
    if(mi<qur) ans=ans+query(wtf->ch[1],mi+1,rt,qul,qur);
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    build(root,1,n);
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(root,1,n,l,r).mims<<endl;
    }
    return 0;
}