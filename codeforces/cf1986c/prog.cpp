// CF1986C - Update Queries
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,ix[N],h;
string s,c;
void solve(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i) cin>>ix[i];
    cin>>c;
    sort(ix+1,ix+m+1);
    sort(c.begin(),c.end());
    h=unique(ix+1,ix+m+1)-ix;
    for(int i=1;i<h;++i) s[ix[i]-1]=c[i-1],cerr<<ix[i]<<" ";
    cerr<<endl;
    cout<<s<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}