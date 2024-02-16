#include <bits/stdc++.h>
using namespace std;
int n,t,f[10010];
void solve(int tid){
    int ans=0;
    cin>>n>>t;
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;++i){
        int h;
        cin>>h;
        for(int j=t-1;j>=h;--j){
            f[j]=max(f[j],f[j-h]+1);
        }
    }
    for(int i=ans=t-1;i>=0;--i) if(f[i]>f[ans]) ans=i;
    cout<<"Case "<<tid<<": "<<f[ans]+1<<" "<<ans+678<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i) solve(i);
    return 0;
}