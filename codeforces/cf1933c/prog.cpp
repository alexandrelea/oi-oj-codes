// Codeforces 1933C - Turtle Fingers: Count the Values of k
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int a,b,l,t;
int pw(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
    return ans;
}
void solve(){
    set<int> S;
    cin>>a>>b>>l;
    int at=0,bt=0,k,ans=0;
    t=l;
    while(t%a==0) t/=a,++at;
    t=l;
    while(t%b==0) t/=b,++bt;
    for(int i=0;i<=at;++i){
        for(int j=0;j<=bt;++j){
            if(l%(pw(a,i)*pw(b,j))==0) ans+=(!S.count(l/(pw(a,i)*pw(b,j)))),S.insert(l/(pw(a,i)*pw(b,j)));
            else break;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}