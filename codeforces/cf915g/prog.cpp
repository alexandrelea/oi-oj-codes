#include <iostream>
using namespace std;
const int MOD=1e9+7,SIZE=2e6+10;
int n,k,pc;
int pw[SIZE],mu[SIZE],p[SIZE],b[SIZE*2];
bool vis[SIZE];
void sieve(){
    mu[1]=1;
    for(int x=2;x<=k;x++){
        if(!vis[x]) p[++pc]=x,mu[x]=-1;
        for (int j=1;x*p[j]<=k;j++)
            if(x%p[j]==0){
                mu[x*p[j]]=0;
                vis[x*p[j]]=true;
                break;
            }else{
                mu[x*p[j]]=-mu[x];
                vis[x*p[j]]=true;
            }
    }
}
int pow(int x,int k){
    int ret=1;
    while(k){
        if(k&1) ret=(long long)ret*x%MOD;
        x=(long long)x*x%MOD;
        k>>=1;
    }
    return ret;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) pw[i]=pow(i,n);
    sieve();
    for(int x=1;x<=k;++x){
        for(int i=1;i*x<=k;++i){
            b[i*x]=(b[i*x]+(long long)pw[i]*(MOD+mu[x])%MOD)%MOD;
            b[i*x]=(b[i*x]-(long long)pw[i-1]*(MOD+mu[x]%MOD))%MOD;
            if (b[i*x]<0) b[i*x]+=MOD;
        }
    }
    int ans=0;
    for (int i=1;i<=k;i++) b[i]=(b[i]+b[i-1])%MOD,ans=(ans+(b[i]^i)%MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}