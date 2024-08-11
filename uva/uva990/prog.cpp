// UVa990 - Diving for Gold
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int t,w,n,d[35],v[35],f[35][1005],co[35][1005];
void solve(){
    memset(f,0,sizeof f);
    memset(co,0,sizeof co);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>d[i]>>v[i],d[i]*=3*w;
    for(int i=1;i<=n;++i) for(int j=1;j<=t;++j){
        if(j>=d[i]&&(f[i-1][j-d[i]]+v[i]>f[i-1][j])){
            f[i][j]=f[i-1][j-d[i]]+v[i];
            co[i][j]=1;
        }else f[i][j]=f[i-1][j];
    }
    int idx=n,cap=t;
    vector<int> ans;
    while(idx>=1){
        if(co[idx][cap]) ans.push_back(idx),cap-=d[idx];
        --idx;
    }
    cout<<f[n][t]<<endl<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(int ie:ans) cout<<(d[ie]/(3*w))<<" "<<v[ie]<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    bool ok=false;
    while(cin>>t>>w){
        if(ok) cout<<endl;
        solve();
        ok=true;
    }
    return 0;
}