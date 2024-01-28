#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],ans;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    sort(a+1,a+n+1),sort(b+1,b+m+1);
    b[0]=1e18+7;
    int lf=0,rt=2e9;
    while(lf<=rt){
        int mi=lf+(rt-lf+1)/2,cnt=0;
        for(int i=1;i<=n;++i){
            int h=lower_bound(b+1,b+m+1,a[i])-b,g=h-1;
            if(h>m) h=g=m;
            if(abs(a[i]-b[h])<=mi||abs(a[i]-b[g])<=mi) cnt++;
        }
        if(cnt==n) ans=mi,rt=mi-1;
        else lf=mi+1;
    }
    cout<<ans<<endl;
    return 0;
}