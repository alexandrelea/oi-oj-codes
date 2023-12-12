#include <bits/stdc++.h>
using namespace std;
int n,s,m,l,memo[110];
int dfs(int x){
    cerr<<"d "<<x<<endl;
    if(x<=0) return 0;
    if(memo[x]!=-1) return memo[x];
    return memo[x]=min(dfs(x-6)+s,min(dfs(x-8)+m,dfs(x-12)+l));
}
int main(){
    memset(memo,-1,sizeof(memo));
    cin>>n>>s>>m>>l;
    cout<<dfs(n)<<endl;
    return 0;
}