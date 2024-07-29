#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int vis[N],p,q,r,s,pr[N],cp,epr[N];
void factorization(int nu,int del){
    int pcnt=1;
    while(nu!=1){
        while(nu%pr[pcnt]==0) nu/=pr[pcnt],epr[pcnt]+=del;
        ++pcnt;
    }
}
void factorial(int nu,int del){
    for(int i=nu;i>=2;--i){
        factorization(i,del);
    }
}
void binomial(int n,int m,int del){
    factorial(n,del);
    factorial(m,-del);
    factorial(n-m,-del);
}
int main(){
    memset(vis,1,sizeof vis);
    vis[0]=vis[1]=0;
    for(int i=2;i<10000;++i){
        if(vis[i]) pr[++cp]=i;
        for(int j=1;j<=cp&&i*pr[j]<10000;++j){
            vis[i*pr[j]]=0;
            if(i%pr[j]==0) break;
        }
    }
    while(cin>>p>>q>>r>>s){
        memset(epr,0,sizeof epr);
        binomial(p,q,1);
        binomial(r,s,-1);
        double ans=1.0;
        for(int i=1;i<=cp;++i) ans*=pow(pr[i],epr[i]);
        cout<<fixed<<setprecision(5)<<ans<<endl;
    }
    return 0;
}