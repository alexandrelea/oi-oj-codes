// UVa1398 - Meteor
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,short> event;
double w,h;
int n;
void wiwt(double p,double v,double x,double &lt,double &rt){
    if(v==0){
        if(p<=0||p>=x) rt=lt-1;
    }else if(v>0){
        // p+vt=x,t=(x-p)/v
        lt=max(lt,-p/v);
        rt=min(rt,(x-p)/v);
    }else{
        lt=max(lt,(x-p)/v);
        rt=min(rt,-p/v);
    }
}
void solve(){
    cin>>w>>h>>n;
    vector<event> es;
    for(int i=1;i<=n;++i){
        double x,y,a,b,l=0,r=1e10;
        cin>>x>>y>>a>>b;
        wiwt(x,a,w,l,r),wiwt(y,b,h,l,r);
        if(r>l) es.push_back({l,1}),es.push_back({r,0});
    }
    sort(es.begin(),es.end());
    int cnt=0,ans=0;
    for(auto ie:es){
        auto ty=ie.second;
        if(ty) ans=max(ans,++cnt);
        else --cnt;
    }
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}