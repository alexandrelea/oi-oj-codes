// CF2000D - Right Left Wrong
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n;
ll a[N],aa[N],cnt[N];
string s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>s,s=" "+s,cnt[n+1]=0;
    for(int i=1;i<=n;++i) aa[i]=aa[i-1]+a[i];
    for(int i=n;i>=1;--i) cnt[i]=cnt[i+1]+(s[i]=='R');
    for(int i=1;i<=n;++i) if(s[i]=='R') --cnt[i];
    vector<pair<int,int>> res;
    stack<int> st;
    for(int i=1;i<=n;++i){
        if(s[i]=='R'){
            int ke=cnt[i],L=-1;
            while(st.size()>ke) L=st.top(),st.pop();
            if(L!=-1) res.push_back(make_pair(L,i));
        }else st.push(i);
    }
    ll ans=0;
    for(auto ie:res) ans+=aa[ie.second]-aa[ie.first-1];
    cout<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}