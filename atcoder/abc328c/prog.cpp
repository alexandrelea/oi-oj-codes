#include <bits/stdc++.h>
using namespace std;
const int N=3e5,NN=N+10;
int n,q;
string s;
struct dta{
    int ocur;
    char lch,rch;
    dta(int oc=0,char lc='\0',char rc='\0'):ocur(oc),lch(lc),rch(rc){}
    dta operator+(const dta &rhs)const{
        if(lch=='\0'&&rch=='\0'&&ocur==0) return rhs;
        return dta(ocur+rhs.ocur+(rch==rhs.lch),lch,rhs.rch);
    }
}wtf[NN*4];
void build(int co,int lf,int rt){
    if(lf==rt){
        wtf[co]=dta(0,s[lf],s[lf]);
        return;
    }
    int mi=lf+(rt-lf)/2;
    build(co*2,lf,mi);
    build(co*2+1,mi+1,rt);
    wtf[co]=wtf[co*2]+wtf[co*2+1];
    assert(wtf[co].lch==s[lf]&&wtf[co].rch==s[rt]);
}
dta query(int co,int lf,int rt,int qlf,int qrt){
    if(qlf<=lf&&rt<=qrt) return wtf[co];
    int mi=lf+(rt-lf)/2;
    dta qans=dta();
    if(qlf<=mi) qans=qans+query(co*2,lf,mi,qlf,qrt);
    if(mi<qrt) qans=qans+query(co*2+1,mi+1,rt,qlf,qrt);
    return qans;
}
int main(){
    cin>>n>>q>>s;
    s=" "+s;
    build(1,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r).ocur<<endl;
    }
    return 0;
}