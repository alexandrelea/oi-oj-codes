// 洛谷 p2627 - Mowing the Lawn G
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n,k,fr,bk;
ll f[N],e[N],ee[N],que[N];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>e[i],ee[i]=e[i]+ee[i-1];
    for(int i=1;i<=n;++i){
        e[i]=f[i-1]-ee[i];
        while(fr<=bk&&e[que[bk]]<e[i]) --bk;
        que[++bk]=i;
        while(fr<=bk&&que[fr]<i-k) ++fr;
        f[i]=ee[i]+e[que[fr]];
    }
    cout<<f[n]<<endl;
    return 0;
}