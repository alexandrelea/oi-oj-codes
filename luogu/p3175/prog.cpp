#include <bits/stdc++.h>
using namespace std;
const double eps=1e-12;
int n,cnt[1<<20],all,iinf;
double g[1<<20],ans;
int main(){
    cin>>n;
    for(int i=1;i<(1<<n);++i){
        int x=i;
        while(x) x-=x&(-x),++cnt[i];
    }
    for(int i=0;i<(1<<n);++i) cin>>g[i];
    for(int i=0;i<n;++i) for(int j=0;j<(1<<i);++j) for(int k=0;k<(1<<(n-i-1));++k)
        g[j+(k<<(i+1))+(1<<i)]+=g[j+(k<<(i+1))];
    all=(1<<n)-1;
    for(int i=1;i<(1<<n);++i){
        int p=-1;
        if(cnt[i]&1) p=1;
        if(abs(1.0-g[all^i])<eps) iinf+=p;
        else ans+=p*1.0/(1.0-g[all^i]);
    }
    if(iinf) cout<<"INF"<<endl;
    else cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}