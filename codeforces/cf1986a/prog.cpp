// CF1986A - X Axis
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a[4],ans=0x3f3f3f3f;
    for(int i=1;i<=3;++i) cin>>a[i];
    sort(a+1,a+4);
    for(int p=a[1];p<=a[3];++p){
        if(abs(p-a[1])+abs(p-a[2])+abs(p-a[3])<=ans) ans=abs(p-a[1])+abs(p-a[2])+abs(p-a[3]);
    }
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}