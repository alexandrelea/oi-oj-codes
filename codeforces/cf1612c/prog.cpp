#include <iostream>
using namespace std;
long long t,n,k,l1,r1,l2,r2,sum1=0,sum2=0,ans=0;
long long ef(long long l,long long r){
    l1=r1=l2=sum1=sum2=0;
    long long mid;
    while(l<=r){
        mid=(r+l)>>1;
        if(mid>=n){
            sum1=(1+n)*n/2;
            l1=n-1;
            r1=mid-n;
            r2=l1-r1+1;
            sum2=(l1+r2)*r1/2;
            sum1+=sum2;
        }else{
            sum1=(1+mid)*mid/2;
        }
        if(sum1>=k){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return min(2*n-1,l);
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<ef(1,(2*n)-1)<<endl;
    }
    return 0;
}