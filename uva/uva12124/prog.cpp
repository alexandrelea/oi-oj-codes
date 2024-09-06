// UVa 12124 - Assemble
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int cnt;
map<string,int> id;
int gid(string s){
    if(!id.count(s)) id[s]=++cnt;
    return id[s];
}
const int N=10005;
struct cO{
    int pr,qu;
};
int n,b;
vector<cO> com[N];
bool ok(int q){
    int sum=0;
    for(int i=1;i<=cnt;++i){
        int chp=b+1,m=com[i].size();
        for(auto je:com[i]) if(je.qu>=q) chp=min(chp,je.pr);
        if(chp==b+1) return 0;
        sum+=chp;
        if(sum>b) return 0;
    }
    return 1;
}
int main(){
    int _;
    cin>>_;
    while(_--){
        cin>>n>>b;
        cnt=0;
        for(int i=1;i<=n;++i) com[i].clear();
        id.clear();
        int mq=0;
        for(int i=1;i<=n;++i){
            string t,n;
            int p,q;
            cin>>t>>n>>p>>q;
            mq=max(mq,q);
            com[gid(t)].push_back(cO{p,q});
        }
        int L=0,R=mq;
        while(L<R){
            int M=L+(R-L+1)/2;
            ok(M)?L=M:R=M-1;
        }
        cout<<L<<endl;
    }
    return 0;
}