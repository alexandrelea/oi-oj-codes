#include <iostream>
#include <map>
#include <cmath>
#define int long long
using namespace std;
void exgcd(int a,int b,int &x,int &y,int &g){
    if(b==0) x=1,y=0,g=a;
    else exgcd(b,a%b,y,x,g),y-=a/b*x;
}
int log(int a,int b,int p){
    map<int,int> hsh;
    a%=p,b%=p;
    if(b==1||p==1) return 0;
    int d,ax=1,cnt=0,x,y;
    while(exgcd(a,p,x,y,d),d^1){
        if(b%d) return -1;
        b/=d,p/=d,cnt++;
        ax=ax*(a/d)%p;
        if(ax==b) return cnt;
    }
    exgcd(ax,p,x,y,d);
    int inv=(x%p+p)%p;
    b=b*inv%p;

    int t=ceil(sqrt(p)),val=1;
    for(int i=0;i<t;i++) hsh[b*val%p]=i,val=val*a%p;
    a=val,val=1;
    if(!a) return !b?1+cnt:-1;
    for(int i=0,j;i<=t;i++){
        j=(hsh.find(val)==hsh.end()?-1:hsh[val]);
        if(~j&&i*t-j>=0) return i*t-j+cnt;
        val=val*a%p;
    }
    return -1;
}
signed main(){
    int a,b,p;
    while(cin>>a>>p>>b&&(a!=0||b!=0||p!=0)){
        a%=p,b%=p;
        int t=log(a,b,p);
        if(t==-1) cout<<"No Solution"<<endl;
        else cout<<t<<endl;
    }
    return 0;
}