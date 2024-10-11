// 洛谷 - p1213 [USACO1.4] [IOI1994]时钟 The Clocks
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int cks[15],cnt[15];
string mv[15]={"","ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
void mov(int idx){
    for(size_t i=0;i<mv[idx].length();++i) cks[mv[idx][i]-'A']++,cks[mv[idx][i]-'A']%=4;
}
bool dfs(int dep){
    if(dep==11){
        int sum=0;
        for(int i=0;i<9;++i) sum+=cks[i];
        return sum==0;
    }
    for(cnt[dep]=0;cnt[dep]<=3;++cnt[dep],mov(dep)) if(dfs(dep+1)) return 1;
    return 0;
}
int main(){
    for(int i=0;i<9;++i) cin>>cks[i],cks[i]/=3,cks[i]%=4;
    dfs(1);
    for(int i=1;i<=10;++i) while(cnt[i]) cout<<i<<" ",--cnt[i];
    return 0;
}