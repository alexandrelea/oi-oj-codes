// CF2000B - Seating in a Bus
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
bool vis[N];
void solve(){
    cin>>n;
    memset(vis,0,sizeof vis);
    bool ok=true;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        vis[x]=1;
        if(i!=1) ok&=(vis[x-1]||vis[x+1]);
    }
    cout<<(ok?string("yes"):string("no"))<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}