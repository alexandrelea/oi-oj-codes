#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long ulnt;
int n;
ulnt ans=0;
string s[2];
map<pair<ulnt,ulnt>,int> mono;
void dfs(int x,ulnt hs1,ulnt hs2,bool fg){
    if(x>n){
        if(fg) ans+=mono[make_pair(hs1,hs2)];
        else mono[make_pair(hs1,hs2)]++;
        return;
    }
    dfs(x+1,hs1*127ull+s[fg][x-1],hs2,fg);
    dfs(x+1,hs1,hs2*127ull+s[fg][x-1],fg);
}
int main(){
    cin>>n>>s[0];
    s[1]=s[0].substr(n,n);
    reverse(s[1].begin(),s[1].end());
    s[0]=s[0].substr(0,n);
    dfs(1,0,0,0);
    dfs(1,0,0,1);
    cout<<ans<<endl;
    return 0;
}