#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,k;
int que[N],fr,bk,hot[N];
bool ans[N];
struct ev{
    int ts,id;
    ev(int ts=0,int id=0):ts(ts),id(id){}
}eves[N];
int main(){
    cin>>n>>d>>k;
    for(int i=1;i<=n;++i) cin>>eves[i].ts>>eves[i].id;
    sort(eves+1,eves+n+1,[](ev a,ev b)->bool {return a.ts<b.ts;});
    for(int i=1;i<=n;++i){
        while(fr<bk&&eves[i].ts-eves[que[fr]].ts>=d) hot[eves[que[fr]].id]--,++fr;
        que[bk++]=i,hot[eves[i].id]++;
        if(hot[eves[i].id]>=k) ans[eves[i].id]=true;
    }
    for(int i=0;i<=N-10;++i) if(ans[i]) cout<<i<<endl;
    return 0;
}