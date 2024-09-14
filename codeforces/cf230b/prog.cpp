// Codeforces 230B - T-primes
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
unordered_set<ll> tpr;
ll pr[N],cp;
bool vis[N];
int main(){
    for(ll i=2;i<N;++i){
        if(!vis[i]) pr[++cp]=i,tpr.insert(i*i);
        for(ll j=1;j<=cp&&i*pr[j]<N;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    int _;
    cin>>_;
    while(_--){
        ll x;
        cin>>x;
        if(tpr.count(x)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}