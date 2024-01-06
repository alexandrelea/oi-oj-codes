#include <bits/stdc++.h>
using namespace std;
int n,r[4];
void dfs(int st,int last){
    if(st==4){
        cout<<r[1]<<" "<<r[2]<<" "<<r[3]<<endl;
        return;
    }
    for(int i=0;i<=last;++i){
        r[st]=i;
        dfs(st+1,last-i);
    }
}
int main(){
    cin>>n;
    dfs(1,n);
    return 0;
}