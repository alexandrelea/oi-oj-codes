#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dlim,mans=0x3f3f3f3f;
vector<ll> ans,res;
bool dfs(int dep,ll milim,ll a,ll b){
    if(a<0||b<0) return 0;
    if(dep==dlim){
        if(b%a!=0) return 0;
        res.push_back(b/a);
        int mres=0;
        for(int ie:res) mres=max(mres,ie);
        if(mres<mans) ans=res,mans=mres;
        res.pop_back();
        return 1;
    }
    bool ok=0;
    milim=max(milim,b/a+1);
    for(ll i=milim;;++i){
        if((dlim-dep+1)*b<=i*a) break;
        res.push_back(i);
        ll a_=a*i-b,b_=i*b,g=__gcd(a_,b_);
        a_/=g,b_/=g;
        ok|=dfs(dep+1,i+1,a_,b_);
        res.pop_back();
    }
    return ok;
}
int main(){
    ll a,b;
    cin>>a>>b;
    for(dlim=1;;++dlim){
        ans.clear();
        if(dfs(0,b/a+1,a,b)) break;
    }
    for(int ie:ans) cout<<ie<<" ";
    return 0;
}