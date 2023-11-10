#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct data{
    int lfm,rtm,inm,sum;
    data(int lfm=-INF,int rtm=-INF,int inm=-INF,int sum=0)
        :lfm(lfm),rtm(rtm),inm(inm),sum(sum){}
    data operator+(const data &rhs)const{
        return data(
            max(lfm,sum+rhs.lfm),
            max(rhs.rtm,rtm+rhs.sum),
            max(rtm+rhs.lfm,max(inm,rhs.inm)),
            sum+rhs.sum
        );
    }
};
struct omg{
    int lf,rt;
    omg *ch[2];
    data dta;
    omg(int lf=0,int rt=0,omg *lch=nullptr,omg *rch=nullptr,data dta=data()):lf(lf),rt(rt),dta(dta){
        ch[0]=lch,ch[1]=rch;
    }
}*root;
int n,a[50010],q;
void build(omg *&wtf,int lf,int rt){
    if(wtf==nullptr) wtf=new omg(lf,rt);
    if(lf==rt){
        wtf->dta=data(a[lf],a[lf],a[lf],a[lf]);
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(wtf->ch[0],lf,mi);
    build(wtf->ch[1],mi+1,rt);
    wtf->dta=wtf->ch[0]->dta+wtf->ch[1]->dta;
}
void modify(omg *wtf,int pos,int val){
    if(wtf->lf==wtf->rt){
        wtf->dta=data(val,val,val,val);
        return;
    }
    if(pos<=wtf->ch[0]->rt) modify(wtf->ch[0],pos,val);
    else modify(wtf->ch[1],pos,val);
    wtf->dta=wtf->ch[0]->dta+wtf->ch[1]->dta;
}
data query(omg *wtf,int qlf,int qrt){
    if(qlf<=wtf->lf&&wtf->rt<=qrt) return wtf->dta;
    data qans=data();
    if(qlf<=wtf->ch[0]->rt) qans=qans+query(wtf->ch[0],qlf,qrt);
    if(wtf->ch[1]->lf<=qrt) qans=qans+query(wtf->ch[1],qlf,qrt);
    return qans; 
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(root,1,n);
    cin>>q;
    while(q--){
        int o,x,y;
        cin>>o>>x>>y;
        if(o==0) modify(root,x,y);
        else cout<<query(root,x,y).inm<<endl;
    }
    return 0;
}