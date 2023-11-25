#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,ans=0,as=0,bs=0,cs=0;
vector<int> a,b,c;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1,t;i<=n;++i){
        bool aa,bb;
        cin>>t>>aa>>bb;
        if(aa&&bb) c.push_back(t);
        else if(aa) a.push_back(t);
        else if(bb) b.push_back(t);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    as=a.size(),bs=b.size();
    for(int i=0;i<min(as,bs);++i) c.push_back(a[i]+b[i]);
    sort(c.begin(),c.end());
    cs=c.size();
    if(cs<k) cout<<-1<<endl;
    else{
        for(int i=0;i<k;++i) ans+=c[i];
        cout<<ans<<endl;
    }
    return 0;
}