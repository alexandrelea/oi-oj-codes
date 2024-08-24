// ABC368C - Triple Attack
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2'00'005;
int n,h[N];
int atk(int &x){
    if(x<2) return ++x,1;
    else return x=0,3;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i];
    int ans=0,la=0;
    for(int i=1;i<=n;++i){
        if(h[i]%5==0) ans+=h[i]/5*3;
        else{
            ans+=h[i]/5*3;
            h[i]%=5;
            if(h[i]>=1) h[i]-=atk(la),++ans;
            if(h[i]>=1) h[i]-=atk(la),++ans;
            if(h[i]>=1) h[i]-=atk(la),++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}