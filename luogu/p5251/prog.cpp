#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
int n,m,c,a[N],b[N],ocur[110]={};
struct nodt{
    int lf,rt;
    mutable int val;
    nodt(int lf,int rt=0,int val=0):lf(lf),rt(rt),val(val){}
    bool operator<(const nodt &rhs)const{
        return lf<rhs.lf;
    }
};
set<nodt> odt;
typedef set<nodt>::iterator iter;
iter split(int pos){
    iter it=odt.lower_bound(nodt(pos));
    if(it!=odt.end()&&it->lf==pos) return it;
    --it;
    int lf=it->lf,rt=it->rt,val=it->val;
    odt.erase(it);
    odt.insert(nodt(lf,pos-1,val));
    return odt.insert(nodt(pos,rt,val)).first;
}
void assign(int lf,int rt,int col){
    iter itr=split(rt+1),itl=split(lf);
    odt.erase(itl,itr);
    odt.insert(nodt(lf,rt,col));
}
struct dat{
    int sum,mims,mxms;
    dat(int sum=0,int mims=INF,int mxms=-INF):sum(sum),mims(mims),mxms(mxms){}
    dat operator+(const dat &rhs)const{
        return dat(sum+rhs.sum,min(mims,rhs.mims),max(mxms,rhs.mxms));
    }
};
struct nseg{
    dat dta;
    nseg *ch[2];
    nseg(dat dta=dat(),nseg *lfch=nullptr,nseg *rtch=nullptr):dta(dta){
        ch[0]=lfch,ch[1]=rtch;
    }
}*root;
void build(nseg *&co,int lf,int rt){
    co=new nseg;
    if(lf==rt){
        co->dta=dat(a[lf],a[lf],a[lf]);
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(co->ch[0],lf,mi);
    build(co->ch[1],mi+1,rt);
    co->dta=co->ch[0]->dta+co->ch[1]->dta;
}
void modify(nseg *&co,int lf,int rt,int pos,int val){
    if(lf==rt){
        co->dta=dat(val,val,val);
        return;
    }
    int mi=lf+(rt-lf)/2;
    if(pos<=mi) modify(co->ch[0],lf,mi,pos,val);
    else modify(co->ch[1],mi+1,rt,pos,val);
    co->dta=co->ch[0]->dta+co->ch[1]->dta;
}
dat query(nseg *co,int lf,int rt,int qlf,int qrt){
    if(qlf<=lf&&rt<=qrt) return co->dta;
    int mi=lf+(rt-lf)/2;
    dat ans=dat();
    if(qlf<=mi) ans=ans+query(co->ch[0],lf,mi,qlf,qrt);
    if(mi<qrt) ans=ans+query(co->ch[1],mi+1,rt,qlf,qrt);
    return ans;
}
int allquery(int lf,int rt){
    if(c==1) return query(root,1,n,lf,rt).mims;
    iter itr=split(rt+1),itl=split(lf);
    int ans=INF,tot=0;
    memset(ocur,0,sizeof(ocur));
    for(iter it=itl;it!=itr;++it){
        if((ocur[it->val]++)==0) ++tot;
        while(tot==c){
            ans=min(ans,query(root,1,n,itl->rt,it->lf).sum);
            if((--ocur[(itl++)->val])==0) --tot;
        }
    }
    return ans==INF?-1:ans;
}
int nalquery(int lf,int rt){
    iter itr=split(rt+1),itl=split(lf);
    int ans=query(root,1,n,lf,rt).mxms;
    memset(ocur,0,sizeof(ocur));
    for(iter it=itl;it!=itr;++it){
        ++ocur[it->val];
        while(it!=itl&&ocur[it->val]>1) --ocur[(itl++)->val];
        if(it!=itl) ans=max(ans,query(root,1,n,itl->rt,it->lf).sum);
        if(it->lf!=it->rt) while(it!=itl) --ocur[(itl++)->val];
    }
    return ans;
}
int main(){
    cin>>n>>m>>c;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    int fr=1;
    for(int i=2;i<=n;++i) if(b[i]!=b[i-1]){
        odt.insert(nodt(fr,i-1,b[fr]));
        fr=i;
    }
    odt.insert(nodt(fr,n,b[fr]));
    root=new nseg;
    build(root,1,n);
    while(m--){
        int l,r,x,y,op;
        cin>>op;
        if(op==1) cin>>x>>y,modify(root,1,n,x,y);
        else if(op==2) cin>>l>>r>>y,assign(l,r,y);
        else if(op==3) cin>>l>>r,cout<<allquery(l,r)<<endl;
        else if(op==4) cin>>l>>r,cout<<nalquery(l,r)<<endl;
    }
    cout<<flush;
    return 0;
}