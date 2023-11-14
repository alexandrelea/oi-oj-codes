#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10,BN=1e3+10;
int a[N],d[N],L[BN],R[BN],belong[N],lazy[BN],ans;
int n,q,block,tot,x,y,k;
char cz;
void build(){
    block=ceil(sqrt(n));
    tot=n/block;
    if(n%block) ++tot;
    for(int i=1;i<=n;++i) belong[i]=(i-1)/block+1,d[i]=a[i];
    for(int i=1;i<=tot;++i) L[i]=(i-1)*block+1,R[i]=i*block;
    R[tot]=n;
    for(int i=1;i<=tot;++i) sort(d+L[i],d+R[i]+1);
}
void change(){
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;++i) a[i]+=k;
        for(int i=L[belong[x]];i<=R[belong[x]];++i) d[i]=a[i];
        sort(d+L[belong[x]],d+R[belong[x]]+1);
        return;
    }
    for(int i=x;i<=R[belong[x]];++i) a[i]+=k;
    for(int i=L[belong[x]];i<=R[belong[x]];++i) d[i]=a[i];
    sort(d+L[belong[x]],d+R[belong[x]]+1);
    for(int i=L[belong[y]];i<=y;++i) a[i]+=k;
    for(int i=L[belong[y]];i<=R[belong[y]];++i) d[i]=a[i];
    sort(d+L[belong[y]],d+R[belong[y]]+1);
    for(int i=belong[x]+1;i<=belong[y]-1;++i) lazy[i]+=k;
}
void query(){
    ans=0;
    if(belong[x]==belong[y]){
        for(int i=x;i<=y;++i) if(lazy[belong[x]]+a[i]>=k) ++ans;
        cout<<ans<<endl;
        return;
    }
    for(int i=x;i<=R[belong[x]];++i) if(lazy[belong[x]]+a[i]>=k) ++ans;
    for(int i=L[belong[y]];i<=y;++i) if(lazy[belong[y]]+a[i]>=k) ++ans;
    for(int i=belong[x]+1;i<=belong[y]-1;++i){
        int ll=L[i],rr=R[i],res=0,mid;
        while(ll<=rr){
            mid=(ll+rr)/2;
            if(d[mid]+lazy[i]>=k) rr=mid-1,res=R[i]-mid+1;
            else ll=mid+1;
        }
        ans+=res;
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    build();
    while(q--){
        cin>>cz>>x>>y>>k;
        if(cz=='M') change();
        if(cz=='A') query();
    }
    return 0;
}