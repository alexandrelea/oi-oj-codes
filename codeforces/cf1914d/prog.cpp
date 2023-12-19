#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,rc[4],ans;
struct kb{
    int v,i;
    kb(int v=0,int i=0):v(v),i(i){}
}a[N],b[N],c[N];
auto cmp=[](const kb &x,const kb &y)->bool {return x.v>y.v;};
void dfs(int p){
    if(p==4){
        if(a[rc[1]].i!=b[rc[2]].i&&b[rc[2]].i!=c[rc[3]].i&&a[rc[1]].i!=c[rc[3]].i){
            ans=max(a[rc[1]].v+b[rc[2]].v+c[rc[3]].v,ans);
        }
        return;
    }
    for(int i=1;i<=3;++i){
        rc[p]=i;
        dfs(p+1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].v,a[i].i=i;
    for(int i=1;i<=n;++i) cin>>b[i].v,b[i].i=i;
    for(int i=1;i<=n;++i) cin>>c[i].v,c[i].i=i;
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    sort(c+1,c+n+1,cmp);
    ans=0;
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}