#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ls;
string s;
ll nu=0,dep;
vector<ll> eqnu;
void solve(){
    cin>>s;
    ls=s.size();
    nu=dep=0;
    eqnu.clear();
    for(int i=0;i<ls;++i){
        if(isalnum(s[i])) nu=nu*10+s[i]-'0';
        else{
            if(nu!=0) eqnu.push_back(nu<<dep);
            nu=0;
            if(s[i]=='[') ++dep;
            else if(s[i]==']') --dep;
            else ;
        }
    }
    if(isalnum(s[ls-1])) eqnu.push_back(nu<<dep);
    sort(eqnu.begin(),eqnu.end());
    int meq=1,ans=1;
    for(int i=1;i<eqnu.size();++i){
        if(eqnu[i]==eqnu[i-1]) ++meq;
        ans=max(meq,ans);
    }
    ans=max(meq,ans);
    cerr<<eqnu.size()<<" "<<ans<<endl;
    cout<<eqnu.size()-ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}