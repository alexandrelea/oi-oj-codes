#include <bits/stdc++.h>
using namespace std;
int n,s[5],t[30],h[30],ans,res=0x3f3f3f3f,tot,amn=0x3f3f3f;
void dfs(int k){
    if(k==n+1){
        int sum=0,mus=0;
        for(int i=1;i<=n;++i) sum+=t[i]*h[i];
        mus=tot-sum;
        if(abs(mus-sum)<amn) amn=abs(mus-sum),res=max(mus,sum);
    }else for(int i=0;i<=1;++i) h[k]=i,dfs(k+1);
}
int main(){
    for(int i=1;i<=4;++i) cin>>s[i];
    for(int i=1;i<=4;++i){
        n=s[i],tot=0;
        for(int j=1;j<=n;++j) cin>>t[j],tot+=t[j];
        dfs(1);
        ans+=res,res=amn=0x3f3f3f3f;
    }
    cout<<ans<<endl;
    return 0;
}