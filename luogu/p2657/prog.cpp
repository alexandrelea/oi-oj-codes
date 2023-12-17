#include <bits/stdc++.h>
using namespace std;
int f[10][15],_[10];
int dp(int d,int n,bool p0,bool fu){
    if((!p0)&&(!fu)&&f[d][n]!=-1) return f[d][n];
    if(d==0) return 1;
    int t=fu?_[d]:9,ans=0;
    for(int i=t;i>=0;--i){
        if(abs(n-i)<2&&(!p0)) continue;
        ans+=dp(d-1,i,p0&&(i==0),fu&&i==t);
    }
    if((!p0)&&(!fu)) f[d][n]=ans;
    return ans;
}
int solve(int n){
    if(n==0) return 1;
    int p=0;
    while(n) _[++p]=n%10,n/=10;
    return dp(p,0,1,1);
}
int main(){
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    memset(f,0xff,sizeof(f));
    cout<<solve(b)-solve(a-1)<<endl;
    return 0;
}