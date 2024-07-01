#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,n;
int fib[1000010];
int fp(int a,int b,int p){
    a%=p;
    int ans=1%p;
    while(b){
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
void solve(){
    int p;
    cin>>a>>b>>n;
    fib[0]=0,fib[1]=1%n;
    for(int i=2;i<=n*n+1;++i){
        fib[i]=(fib[i-1]+fib[i-2])%n;
        if(fib[i]==fib[1]&&fib[i-1]==fib[0]){
            p=i-1;
            break;
        }
    }
    cout<<fib[fp(a,b,p)]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
