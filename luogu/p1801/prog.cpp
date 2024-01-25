#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,_=2e9;
int m,n,a[N],u[N],j;
int val[N*100],tot,rt,ch[N*100][2];
void modify(int &u,int ul,int ur,int p,int k){
    if(u==0) u=++tot;
    if(ul==ur){
        val[u]+=k;
        return;
    }
    int um=ul+(ur-ul)/2;
    if(p<=um) modify(ch[u][0],ul,um,p,k);
    else modify(ch[u][1],um+1,ur,p,k);
    val[u]=val[ch[u][0]]+val[ch[u][1]];
}
int query(int u,int ul,int ur,int ql,int qr){
    if(u==0) return 0;
    if(ql<=ul&&ur<=qr) return val[u];
    int um=ul+(ur-ul)/2,ans=0;
    if(ql<=um) ans+=query(ch[u][0],ul,um,ql,qr);
    if(um<qr) ans+=query(ch[u][1],um+1,ur,ql,qr);
    return ans;
}
int kth(int u,int ul,int ur,int k){
    if(u==0) return -1;
    if(ul==ur) return ul;
    int um=ul+(ur-ul)/2;
    if(k<=val[ch[u][0]]) return kth(ch[u][0],ul,um,k);
    else return kth(ch[u][1],um+1,ur,k-val[ch[u][0]]);
    return -1;
}
signed main(){
    cin>>m>>n;
    for(int i=1;i<=m;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        u[x]++;
    }
    for(int i=1;i<=m;++i){
        modify(rt,-_,_,a[i],1);
        while(u[i]) cout<<kth(1,-_,_,++j)<<endl,--u[i];
    }
    return 0;
}