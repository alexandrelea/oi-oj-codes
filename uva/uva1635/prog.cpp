#include <bits/stdc++.h>
using namespace std;
const int M=1e5;
int n,m,pf[M],pc[M],pn,ec[M];
void uniqfact(int nu,int de){
    for(int i=1;i<=pn;++i) while(nu%pf[i]==0) ec[i]+=de,nu/=pf[i];
}
void solve(){
    pn=0;
    for(int i=2;i*i<=m;++i){
        if(m%i==0){
            pf[++pn]=i,pc[pn]=0;
            while(m%i==0) m/=i,++pc[pn];
        }
    }
    if(m!=1) pf[++pn]=m,pc[pn]=1;
    memset(ec,0,sizeof ec);
    vector<int> ans;
    for(int i=1;i<n;++i){
        uniqfact(n-i,1);
        uniqfact(i,-1);
        bool ok=true;
        for(int j=1;j<=pn;++j) if(ec[j]<pc[j]){
            ok=false;
            break;
        }
        if(ok) ans.push_back(i+1);
    }
    int anss=ans.size();
    cout<<anss<<endl;
    if(anss!=0){
        cout<<ans[0];
        for(int i=1;i<anss;++i) cout<<" "<<ans[i];
    }
    cout<<endl;
}
int main(){
    while(cin>>n>>m) solve();
    return 0;
}