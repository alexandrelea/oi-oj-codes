#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int n,a[2010],hv1,gc[2010*4];
void build(int co,int lf,int rt){
    if(lf==rt) return gc[co]=a[lf],void();
    int mi=lf+(rt-lf)/2;
    build(co*2,lf,mi),build(co*2+1,mi+1,rt);
    gc[co]=gcd(gc[co*2],gc[co*2+1]);
}
int quergy(int co,int lf,int rt,int ql,int qr){
    // cout<<"qrg "<<co<<" "<<lf<<" "<<rt<<" "<<ql<<" "<<qr<<endl;
    if(ql<=lf&&rt<=qr) return gc[co];
    int mi=lf+(rt-lf)/2,qr1=-1,qr2=-1;
    if(ql<=mi) qr1=quergy(co*2,lf,mi,ql,qr);
    if(mi<qr) qr2=quergy(co*2+1,mi+1,rt,ql,qr);
    if(qr1==-1&&qr2!=-1) return qr2;
    else if(qr1!=-1&&qr2==-1) return qr1;
    else return gcd(qr1,qr2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],hv1+=(a[i]==1);
    if(hv1) return cout<<n-hv1<<endl,0;
    build(1,1,n);
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            int ans=quergy(1,1,n,j,j+i);
            if(ans==1) return cout<<i-1+n<<endl,0;
        }
    }
    cout<<-1<<endl;
    return 0;
}