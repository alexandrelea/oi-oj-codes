#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int m,q,sum[N*40],ch[N*40][2],tot,rt,h;
void modify(int &u,int ul,int ur,int p,int k){
    if(u==0) u=++tot;
    if(ul==ur){
        sum[u]+=k;
        return;
    }
    int um=ul+(ur-ul)/2;
    if(p<=um) modify(ch[u][0],ul,um,p,k);
    else modify(ch[u][1],um+1,ur,p,k);
    sum[u]=sum[ch[u][0]]+sum[ch[u][1]];
}
int kth(int u,int ul,int ur,int th){
    if(u==0) return -1;
    if(ul==ur) return ul;
    int um=ul+(ur-ul)/2;
    if(th<=sum[ch[u][0]]) return kth(ch[u][0],ul,um,th);
    else return kth(ch[u][1],um+1,ur,th-sum[ch[u][0]]);
    return -1;
}
int main(){
    cin>>m>>q;
    for(int i=1;i<=m;++i){
        int v;
        cin>>v;
        modify(rt,0,~(1<<31),v,1);
    }
    h=m;
    while(q--){
        int c,n;
        cin>>c>>n;
        if(c==1) cout<<kth(rt,0,~(1<<31),h-n+1)<<endl;
        if(c==2) modify(rt,0,~(1<<31),n,1),++h;
    }
    return 0;
}