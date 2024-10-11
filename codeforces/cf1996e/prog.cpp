// Codeforces 1996E - Decode
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,Z=1e9+7;
string s;
int n,ss[N],f[N];
void solve(){
    cin>>s;
    n=s.size(),s=" "+s;
    for(int i=1;i<=n;++i) ss[i]=(s[i]=='0'?-1:1)+ss[i-1];
    map<int,int> eq;
    // f[i]=1...i max get
    // f[i]=max(f[i-1],(f[j-1]+i-j+1)[ss[i]==ss[j-1]])
    int ans=0;
    eq[0]=1;
    for(int i=1;i<=n;++i){
        ans+=eq[ss[i]]*(n-i+1)%Z,ans%=Z;
        eq[ss[i]]+=i+1,eq[ss[i]]%=Z;
    }
    cout<<(ans+Z)%Z<<endl;
}
signed main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}