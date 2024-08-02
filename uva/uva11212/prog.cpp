#include <bits/stdc++.h>
using namespace std;
int n;
bool dfs(int dep,vector<int> stat,const int lim){
    if(dep==lim){
        for(int i=0;i<n;++i) if(stat[i]!=i) return 0;
        return 1;
    }
    int cnt=0;
    for(int i=0;i<n;++i) if(stat[i+1]!=stat[i]+1) ++cnt;
    if(3*dep+cnt>3*lim) return 0;
    for(int i=0;i<n;++i) for(int j=i;j<n;++j){
        vector<int> cut,resid;
        for(int k=0;k<n;++k){
            if(i<=k&&k<=j) cut.push_back(stat[k]);
            else resid.push_back(stat[k]);
        }
        int rs=resid.size();
        for(int k=0;k<=rs;++k){
            vector<int> exstat;
            for(int l=0;l<k;++l) exstat.push_back(resid[l]);
            for(int ie:cut) exstat.push_back(ie);
            for(int l=k;l<rs;++l) exstat.push_back(resid[l]);
            if(dfs(dep+1,exstat,lim)) return 1;
        }
    }
    return 0;
}
int solve(){
    vector<int> star(n),corr(n);
    for(int i=0;i<n;++i) cin>>star[i],--star[i];
    for(int i=0;i<n-1;++i) if(star[i+1]==star[i]+1) corr[star[i]]=1;
    corr[n-1]=1;
    for(int dlim=0;dlim<=n;++dlim) if(dfs(0,star,dlim)) return dlim;
    return -1;
}
int main(){
    int _=0;
    while(cin>>n&&n) cout<<"Case "<<(++_)<<": "<<solve()<<endl;
    return 0;
}