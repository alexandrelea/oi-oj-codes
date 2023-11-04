#include <iostream>
using namespace std;
const int SIZE=2e5+10;
int n,a,b,k,q,t[SIZE];
int aa[SIZE*4],bb[SIZE*4];
void modifya(int co,int lf,int rt,int poq,int wv){
    if(lf==rt) return aa[co]=min(a,(t[lf])),void();
    int mi=lf+(rt-lf)/2;
    if(poq<=mi) modifya(co*2,lf,mi,poq,wv);
    else modifya(co*2+1,mi+1,rt,poq,wv);
    aa[co]=aa[co*2]+aa[co*2+1];
}
void modifyb(int co,int lf,int rt,int poq,int wv){
    if(lf==rt) return bb[co]=min(b,(t[lf])),void();
    int mi=lf+(rt-lf)/2;
    if(poq<=mi) modifyb(co*2,lf,mi,poq,wv);
    else modifyb(co*2+1,mi+1,rt,poq,wv);
    bb[co]=bb[co*2]+bb[co*2+1];
}
int querya(int co,int lf,int rt,int ql,int qr){
    if(qr<ql) return 0;
    if(ql<=lf&&rt<=qr) return aa[co];
    int mi=lf+(rt-lf)/2,ans=0;
    if(ql<=mi) ans+=querya(co*2,lf,mi,ql,qr);
    if(mi<qr) ans+=querya(co*2+1,mi+1,rt,ql,qr);
    return ans;
}
int queryb(int co,int lf,int rt,int ql,int qr){
    if(qr<ql) return 0;
    if(ql<=lf&&rt<=qr) return bb[co];
    int mi=lf+(rt-lf)/2,ans=0;
    if(ql<=mi) ans+=queryb(co*2,lf,mi,ql,qr);
    if(mi<qr) ans+=queryb(co*2+1,mi+1,rt,ql,qr);
    return ans;
}
int main(){
    cin>>n>>k>>a>>b>>q;
    while(q--){
        int op,x,y;
        cin>>op>>x;
        if(op==1) cin>>y,t[x]+=y,modifya(1,1,n,x,y),modifyb(1,1,n,x,y);
        else cout<<queryb(1,1,n,1,x-1)+querya(1,1,n,x+k,n)<<endl;
    }
    return 0;
}