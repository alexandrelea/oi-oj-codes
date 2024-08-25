// UVa1368 - DNA Consensus String
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,l,cnt[1005][4];
int c2i(char ch){
    if(ch=='A') return 0;
    else if(ch=='C') return 1;
    else if(ch=='G') return 2;
    else return 3;
}
void solve(){
    memset(cnt,0,sizeof cnt);
    cin>>n>>l;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=l;++j){
            char ch;
            cin>>ch;
            cnt[j][c2i(ch)]++;
        }
    }
    int ans=0;
    for(int i=1;i<=l;++i){
        int maxc=max(max(cnt[i][0],cnt[i][1]),max(cnt[i][2],cnt[i][3]));
        if(maxc==cnt[i][0]) cout<<"A",ans+=n-cnt[i][0];
        else if(maxc==cnt[i][1]) cout<<"C",ans+=n-cnt[i][1];
        else if(maxc==cnt[i][2]) cout<<"G",ans+=n-cnt[i][2];
        else cout<<"T",ans+=n-cnt[i][3];
    }
    cout<<endl<<ans<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}