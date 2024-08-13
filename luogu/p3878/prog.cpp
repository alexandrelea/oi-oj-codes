// LG3678 - [TJOI2010] 分金币
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6,cool=0.90095;
const int inf=0x3f3f3f3f;
default_random_engine dre;
uniform_real_distribution<double> rlg(0,1);
int n,v[35];
int SA(int k){
    vector<int> a0,a1,v0,v1;
    int ans=0,l0,l1;
    for(int i=1;i<=k;++i) a0.push_back(v[i]),ans+=v[i];
    for(int i=k+1;i<=n;++i) a1.push_back(v[i]),ans-=v[i];
    ans=abs(ans),v0=a0,v1=a1;
    l0=v0.size(),l1=v1.size();
    double te=1e8;
    while(te>=eps){
        int i0=dre()%l0,i1=dre()%l1,res=0;
        swap(v0[i0],v1[i1]);
        for(int ie:v0) res+=ie;
        for(int ie:v1) res-=ie;
        res=abs(res);
        double de=abs(ans-res);
        if(res<ans||exp(-de/te)>rlg(dre)) ans=res,a0=v0,a1=v1;
        else v0=a0,v1=a1;
        te*=cool;
    }
    return ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>v[i];
    if(n==1){
        cout<<v[1]<<endl;
        return;
    }
    int ans=inf;
    for(int i=1;i<=n;++i) ans=min(SA(n/2),ans);
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}