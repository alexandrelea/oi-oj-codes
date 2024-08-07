#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
int k,vis[N*10],pr[N],tot;
int main(){
    vis[0]=vis[1]=1;
    for(int i=2;i<=2e6;++i){
        if(!vis[i]) pr[++tot]=i;
        for(int j=1;i*pr[j]<=2e6;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    while(cin>>k&&k){
        if(!vis[k]) cout<<0<<endl;
        else{
            int p=upper_bound(pr+1,pr+tot+1,k)-(pr+1);
            cout<<pr[1+p]-pr[p]<<endl;
        }
    }
    return 0;
}