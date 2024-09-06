// UVa 714 - Copying Books
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[511];
bool sepr[511];
bool ok(int req){
    ll sum=0,seg=1;
    for(int i=1;i<=n;++i){
        sum+=a[i];
        if(sum>req) sum=a[i],seg++;
        if(seg>k) return 0;
    }
    return 1;
}
void solve(){
    ll L=0,R=0,A=0;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i],R+=a[i],L=max(L,(ll)a[i]);
    while(L<R){
        ll M=L+((R-L)>>1);
        if(ok(M)) R=M,A=M;
        else L=M+1;
    }
    A=L,L=0,R=k; // L change left for last, R for sections
    memset(sepr,0,sizeof(sepr));
    for(int i=n;i>0;--i){
        if(R>i) --R,sepr[i]=1;
        else if(L+a[i]>A) --R,sepr[i]=1,L=a[i];
        else L+=a[i];
    }
    cerr<<A<<endl;
    for(int i=1;i<=n;++i){
        cout<<a[i];
        if(i!=n) cout<<" ";
        if(sepr[i]&&i!=n) cout<<"/ ";
    }
    cout<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}