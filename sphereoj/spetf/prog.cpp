// SPETF - Euler Totient Function
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int _,x,pr[N+5],pc,phi[N+5];
bool vis[N+5];
int main(){
    phi[1]=1;
    for(int i=2;i<=N;++i){
        if(!vis[i]) pr[++pc]=i,phi[i]=i-1;
        for(int j=1;j<=pc&&i*pr[j]<=N;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]) phi[i*pr[j]]=phi[i]*(pr[j]-1);
            else{
                phi[i*pr[j]]=pr[j]*phi[i];
                break;
            }
        }
    }
    cin>>_;
    while(_--) cin>>x,cout<<phi[x]<<endl;
    return 0;
}