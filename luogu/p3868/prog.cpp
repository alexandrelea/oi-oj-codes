#include <iostream>
using namespace std;
typedef __int128_t lnt;
lnt exgcd(lnt a,lnt b,lnt &g,lnt &x,lnt &y){
    if(b==0) return x=1,y=0,g=a;
    else return exgcd(b,a%b,g,y,x),y-=a/b*x,g;
}
lnt crt(int n,lnt *a,lnt *b){
    lnt B=1,x=0;
    for(int i=1;i<=n;i++) B*=b[i];
    for(int i=1;i<=n;i++){
        lnt bb=B/b[i],ivbb,q,g;
        exgcd(bb,b[i],g,ivbb,q);
        x=((x+bb*ivbb%B*a[i]%B)%B+B)%B;
    }
    return (x+B)%B;
}
int main(){
    int n;
    lnt a[20],b[20],B=1,x=0;
    long long vl;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>vl,a[i]=vl;
    for(int i=1;i<=n;i++) cin>>vl,b[i]=vl,B*=b[i];
    for(int i=1;i<=n;i++){
        lnt bb=B/b[i],ivbb,q,g;
        exgcd(bb,b[i],g,ivbb,q); // bb*ivbb+Bq=1
        x=((x+bb*ivbb%B*a[i]%B)%B+B)%B;
    }
    cout<<(vl=(x+B)%B)<<endl;
    return 0;
}