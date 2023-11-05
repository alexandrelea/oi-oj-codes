#include <iostream>
#include <iomanip>
#include <cmath>
#define fs(x) fixed<<setprecision(x)
using namespace std;
const int SIZE=2.4e6;
long double wtf[SIZE+10],omg[SIZE+10],pih[SIZE+10];
void init(){
    wtf[0]=wtf[1]=0;
    omg[1]=log10(2.0);
    pih[1]=-log10(0.5)-log10(6);
    for(int i=2;i<=SIZE;i++){
        double k=i;
        wtf[i]=wtf[i-1]+log10(k);
        omg[i]=omg[i-1]+log10(2*2*2*2);
    }
    for(int i=2;i<=SIZE/2;i++){
        double k=i;
        pih[i]=2*wtf[i-1]-wtf[2*i-2]+omg[i]+log10(2*k-1)-log10(6);
    }
}
int main(){
    int n;
    init();
    while(cin>>n&&n>=0){
        int lf=1,rt=SIZE,ans=0;
        while(lf<rt){
            int mi=lf+(rt-lf)/2;
            if(pih[mi]>n) ans=mi-1,rt=mi;
            else lf=mi+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}