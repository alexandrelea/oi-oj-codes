#include<bits/stdc++.h>
using namespace std;
int A,B,a[12],dp[12][10];
int dfs(int d,int num,bool zero,bool full){
    if((!zero)&&(!full)&&dp[d][num]!=-1) return dp[d][num];
    if(d==0) return 1;
    int top=full?a[d]:9,ans=0;
    for(int i=0;i<=top;i++){
        if(!zero&&abs(num-i)<2) continue;
        ans+=dfs(d-1,i,zero&&(!i),full&&i==top);
    }
    if((!zero)&&(!full)) dp[d][num]=ans;
    return ans;
}
int solve(int n){
    if(n==0) return 1;
    int d=0;
    while(n) a[++d]=n%10,n/=10;
    return dfs(d,0,1,1);
}
int main(){
    cin>>A>>B;
    memset(dp,-1,sizeof(dp));
    cout<<solve(B)-solve(A-1)<<endl;
    return 0;
}