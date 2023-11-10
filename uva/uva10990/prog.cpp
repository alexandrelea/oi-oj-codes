#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
bool isprime[N+10];
int prime[N+10],toti[N+10],stot[N+10],sumtot[N+10],tot;
int main(){
    int T;
    cin>>T;
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    toti[1]=1;
    for(int i=2;i<=N;i++){
        if(isprime[i]) prime[++tot]=i,toti[i]=i-1;
        for(int j=1;j<=tot&&i*prime[j]<=N;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0){
                toti[i*prime[j]]=toti[i]*prime[j];
                break;
            }else toti[i*prime[j]]=toti[i]*toti[prime[j]];
        }
    }
    stot[1]=0;
    for(int i=2;i<=N;i++) stot[i]=stot[toti[i]]+1,sumtot[i]=stot[i]+sumtot[i-1];
    while(T--){
        int n,m;
        cin>>n>>m;
        cout<<sumtot[m]-sumtot[n-1]<<endl;
    }
    return 0;
}