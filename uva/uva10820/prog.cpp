#include <bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,pr[N+10],np,ephi[N+10];
bool dpr[N+10];
int main(){
    memset(dpr,1,sizeof dpr);
    dpr[0]=dpr[1]=false;
    for(int i=2;i<=N;++i){
        if(dpr[i]) pr[++np]=i,ephi[i]=i-1;
        for(int j=1;j<=np&&i*pr[j]<=N;++j){
            dpr[i*pr[j]]=0;
            if(i%pr[j]==0){
                ephi[i*pr[j]]=ephi[i]*pr[j];
                break;
            }
            ephi[i*pr[j]]=ephi[i]*ephi[pr[j]];
        }
    }
    while(cin>>n&&n>0){
        int ans=0;
        for(int i=2;i<=n;++i) ans+=ephi[i];
        ans=ans*2+1;
        cout<<ans<<endl;
    }
    return 0;
}