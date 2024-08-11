#include <iostream>
#define int long long
using namespace std;
int modmul(int a,int b,int p){
    int x=0,y=a%p;
    while(b){
        if(b%2==1) x=(x+y)%p;
        y=y*2%p;
        b/=2;
    }
    return x;
}
int modpow(int b,int e,int p){
    int x=1,y=b;
    while(e){
        if(e%2==1) x=modmul(x,y,p);
        y=modmul(y,y,p);
        e/=2;
    }
    return x;
}
bool isprime(int p){
    if(p<2) return false;
    if(p==2) return true;
    if(p%2==0) return false;
    int q=p-1;
    while(q%2==0) q/=2;
    for(int i=0;i<100;i++){
        int a=rand()%(p-1)+1,t=q,mod=modpow(a,t,p);
        while(t!=p-1&&mod!=1&&mod!=p-1) mod=modmul(mod,mod,p),t*=2;
        if(mod!=p-1&&t%2==0) return false;
    }
    return true;
}
signed main(){
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        if(isprime(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}