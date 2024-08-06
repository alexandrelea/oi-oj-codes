#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,k,a[N];
void quso(int l,int r){
    if(l>=r) return;
    int pv=a[l],mk=l;
    for(int i=l+1;i<=r;++i) if(a[i]<pv) ++mk,swap(a[mk],a[i]);
    swap(a[l],a[mk]);
    if(k<mk) quso(l,mk-1);
    else if(k>mk) quso(mk+1,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k,++k;
    for(int i=1;i<=n;++i) cin>>a[i];
    quso(1,n);
    cout<<a[k]<<endl;
    return 0;
}