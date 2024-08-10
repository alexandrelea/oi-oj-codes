#include <iostream>
using namespace std;
typedef long long ll;
typedef __int128 i128;
int n;
i128 a[20],b[20];
void exgcd(i128 a,i128 b,i128 &x,i128 &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
i128 crt(int n,i128 *a,i128 *b){
    i128 B=1,x=0;
    for(int i=1;i<=n;i++) B*=b[i];
    for(int i=1;i<=n;i++){
        i128 bb=B/b[i],ivbb,q;
        exgcd(bb,b[i],ivbb,q);
        x=((x+bb*ivbb%B*a[i]%B)%B+B)%B;
    }
    return (x+B)%B;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll v;
        cin>>v,a[i]=v;
        cin>>v,b[i]=v;
    }
    ll h;
    cout<<(h=crt(n,b,a))<<endl;
    return 0;
}