// UVa 10382 - Watering Grass
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,m;
double l,w;
vector<pair<double,double>> sip;
void solve(){
    m=0;
    for(int i=1;i<=n;++i){
        double r,p,q;
        cin>>p>>r;
        if(r<w/2.0) continue;
        q=sqrt(r*r-w*w/4.0);
        sip.push_back(make_pair(p-q,p+q));
        ++m;
    }
    sort(sip.begin(),sip.end());
    int ans=0,i=-1;
    bool ok=1;
    double p=0;
    while(p<l&&i<m){
        int mj=i;
        for(int j=i+1;sip[j].first<=p&&j<m;++j) if(sip[j].second>sip[mj].second) mj=j;
        if(mj<=i){
            ok=0;
            break;
        }
        p=sip[i=mj].second,++ans;
    }
    cout<<(ok?ans:-1)<<endl;
    sip.clear();
}
int main(){
    while(cin>>n>>l>>w) solve();
    return 0;
}