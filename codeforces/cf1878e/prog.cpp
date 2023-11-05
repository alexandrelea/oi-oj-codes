#include <iostream>
using namespace std;
const int SIZE=2e5+10;
int t,n,q,a[SIZE],seg[SIZE<<4];
void build(int co,int lf,int rt){
    if(lf==rt) return seg[co]=a[lf],void();
    int mi=lf+(rt-lf)/2;
    build(co*2,lf,mi),build(co*2+1,mi+1,rt);
    seg[co]=seg[co*2]&seg[co*2+1];
}
int query(int co,int lf,int rt,int ql,int qr){
    if(ql<=lf&&rt<=qr) return seg[co];
    int mi=lf+(rt-lf)/2,qry=0xffffffff;
    if(ql<=mi) qry&=query(co*2,lf,mi,ql,qr);
    if(mi<qr) qry&=query(co*2+1,mi+1,rt,ql,qr);
    return qry;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,1,n);
        cin>>q;
        while(q--){
            int l,k;
            cin>>l>>k;
            int lfr=l,rtr=n,ans=-1;
            if(a[l]<k){
                cout<<-1<<" ";
                continue;
            }
            while(lfr<=rtr){
                int mir=(lfr+rtr)/2,qans=query(1,1,n,l,mir);
                if(qans>=k) ans=mir,lfr=mir+1;
                else rtr=mir-1;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}