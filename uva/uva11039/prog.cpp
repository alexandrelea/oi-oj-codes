// UVa11039 - Building designing
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a[500005];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1,[](int a,int b)->bool {
        return abs(a)<abs(b);
    });
    int sy=a[1]/abs(a[1]),cnt=0;
    for(int i=1;i<=n;++i){
        if(abs(a[i])*sy==a[i]) ++cnt,sy=-sy;
    }
    cout<<cnt<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}