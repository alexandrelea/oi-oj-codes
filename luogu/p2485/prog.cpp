// P2485 - 计算器
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw(ll a,ll b,ll p){
    ll ans=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) ans=ans*a%p;
    return ans;
}
ll log(ll a,ll b,ll p){
    a%=p,b%=p;
    if(a==b) return 1;
    if(a==0&&b) return -1;
    if(b==1) return 0;
    map<ll,ll> ss;
    ll m=(ll)ceil(sqrt(p)),am=pw(a,m,p);
    for(ll i=0;i<=m;++i) ss[b]=i,b*=a,b%=p;
    b=1;
    for(ll i=1;i<=m;++i){
        b*=am,b%=p;
        if(ss.count(b)) return i*m-ss[b];
    }
    return -1;
}
void exgcd(ll a,ll b,ll &g,ll &x,ll &y){
    if(b==0) x=1,y=0,g=a;
    else exgcd(b,a%b,g,y,x),y-=a/b*x;
}
int main(){
    int t,k;
    ll y,z,p;
    cin>>t>>k;
    while(t--){
        cin>>y>>z>>p;
        if(k==1) cout<<pw(y,z,p)<<endl;
        else if(k==2){
            ll k,g,x;
            exgcd(y,p,g,x,k);
            if(z%g!=0) cout<<"Orz, I cannot find x!"<<endl;
            else cout<<(z/g*x%p+p)%p<<endl;
        }else{
            ll ans=log(y,z,p);
            if(ans==-1) cout<<"Orz, I cannot find x!"<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}