// Codeforces 1933B - Turtle Math: Fast Three Task
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m3[3]={},x,S=0;
    cin>>n;
    while(n--) cin>>x,m3[x%3]++,S=(S+x)%3;
    if(S==0) cout<<0<<endl;
    else if(S==1) cout<<(m3[1]!=0?1:2)<<endl;
    else cout<<1<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}