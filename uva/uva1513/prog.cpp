#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,fw[300010],cur[300010];
void sett(int x,int v){
    for(;x<300010;x+=x&(-x)) fw[x]+=v;
}
int gett(int x){
    int ans=0;
    for(;x>0;x-=x&(-x)) ans+=fw[x];
    return ans;
}
signed main(){
    int _;
    cin>>_;
    while(_--){
        cin>>n>>m;
        int po=n;
        for(int i=1;i<=n;++i) sett(i,1),cur[i]=n-i+1;
        bool oed=0;
        while(m--){
            if(oed) cout<<' ';
            int q;
            cin>>q;
            cout<<n-gett(cur[q]);
            sett(cur[q],-1);
            cur[q]=++po;
            sett(cur[q],1);
            oed=1;
        }
        cout<<endl;
        memset(fw,0,sizeof fw);
        memset(cur,0,sizeof cur);
    }
    return 0;
}