// ABC371D - 1D Country
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,x[N],s[N],w[4*N];
void build(int u,int l,int r){
    if(l==r) w[u]=s[l];
    else{
        int m=l+((r-l)>>1);
        build(u<<1,l,m);
        build(u<<1|1,m+1,r);
        w[u]=w[u<<1]+w[u<<1|1];
    }
}
int query(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R) return w[u];
    if(L>R) return 0;
    int m=l+((r-l)>>1),ans=0;
    if(L<=m) ans+=query(u<<1,l,m,L,R);
    if(m<R) ans+=query(u<<1|1,m+1,r,L,R);
    return ans;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=n;++i) cin>>s[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int l,r,b,e;
        cin>>l>>r;
        b=lower_bound(x+1,x+n+1,l)-x,e=lower_bound(x+1,x+n+1,r)-x;
        if(x[e]>r) --e;
        cout<<query(1,1,n,b,e)<<endl;
    }
    return 0;
}