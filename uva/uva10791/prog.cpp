#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll divall(int &n,int p){
    int kh=1;
    while(n%p==0) n/=p,kh*=p;
    return kh;
}
ll solve(){
    if(n==1) return 2;
    ll ans=0,hv=0;
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;++i){
        if(n%i==0){
            ++hv;
            ans+=divall(n,i);
        }
    }
    if(n>1) ans+=n,hv++;
    if(hv<=1) ++ans;
    return ans;
}
int main(){
    int _=0;
    while(cin>>n&&n) cout<<"Case "<<(++_)<<": "<<solve()<<endl;
    return 0;
}