#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],t[N];
long long ans=0;
void meso(int l,int r){
    if(l>=r) return;
    int m=l+(r-l)/2;
    meso(l,m),meso(m+1,r);
    int p=l,q=m+1,o=l;
    while(p<=m&&q<=r){
        if(a[p]>a[q]) ans+=m-p+1,t[o++]=a[q++];
        else t[o++]=a[p++];
    }
    while(p<=m) t[o++]=a[p++];
    while(q<=r) t[o++]=a[q++];
    for(int i=l;i<=r;++i) a[i]=t[i];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    meso(1,n);
    cout<<ans<<endl;
    return 0;
}