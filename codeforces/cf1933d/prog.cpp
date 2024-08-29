// Codeforces 1933D - Turtle Tenacity: Continual Mods
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
map<int,int> cnt;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
bool solve(){
    cnt.clear();
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int g=a[1];
    for(int i=2;i<=n;++i) g=gcd(g,a[i]);
    for(int i=1;i<=n;++i) a[i]/=g,cnt[a[i]]++;
    return cnt[1]>=2?0:1;
}
int main(){
    int _;
    cin>>_;
    while(_--) cout<<(solve()?string("yes"):string("no"))<<endl;
    return 0;
}