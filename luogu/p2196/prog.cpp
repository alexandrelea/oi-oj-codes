#include <bits/stdc++.h>
using namespace std;
int n,w[30];
int stk[30],top;
int ank[30],ant,ans;

vector<int> gr[30];
void dfs(int u,int stc){
    if(gr[u].size()==0){
        if(stc>ans){
            for(int i=1;i<=top;++i) ank[i]=stk[i];
            ant=top,ans=stc;
        }
        return;
    }
    for(int v:gr[u]){
        stk[++top]=v;
        dfs(v,stc+w[v]);
        --top;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int x;
            cin>>x;
            if(x==1) gr[i].push_back(j);
        }
    }
    for(int i=1;i<=n;++i) stk[++top]=i,dfs(i,w[i]),--top;
    for(int i=1;i<=ant;++i) cout<<ank[i]<<" ";
    cout<<endl<<ans<<endl;
    return 0;
}