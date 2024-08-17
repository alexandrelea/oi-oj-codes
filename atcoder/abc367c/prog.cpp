// ATBC367C - Enumerate Sequences
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,r[13],h[13],k;
void dfs(int s,int S){
    if(s==n+1){
        if(S%k==0){
            for(int i=1;i<=n;++i) cout<<h[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=r[s];++i) h[s]=i,dfs(s+1,S+i);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>r[i];
    dfs(1,0);
    return 0;
}