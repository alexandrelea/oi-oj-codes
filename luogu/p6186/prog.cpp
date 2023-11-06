#include <iostream>
#include <cstring>
using namespace std;
typedef long long lnt;
const int SIZE=2e5+10;
lnt t[SIZE],a[SIZE],n,m,biger[SIZE],ans,imp[SIZE];
void add(int x,lnt val){
    for(;x<=n;x+=(x&-x)) t[x]+=val;
}
lnt query(int x){
    lnt qans=0;
    for(;x!=0;x-=(x&-x)) qans+=t[x];
    return qans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        imp[i]=i-query(a[i]);
        ans+=imp[i];
        biger[imp[i]]++;
        add(a[i],1);
    }
    memset(t,0,sizeof(t));
    add(1,ans);
    int cnt=0;
    for(int i=0;i<n;i++) cnt+=biger[i],add(i+2,-(n-cnt));
    while(m--){
        int opt,x;
        cin>>opt>>x;
        x=min((lnt)x,n-1);
        if(opt==1){
            x--;
            int ax=a[x],ax1=a[x+1];
            swap(a[x],a[x+1]);
            swap(imp[x],imp[x+1]);
            if(ax<ax1) add(1,1),add(imp[x+1]+2,-1),imp[x+1]++;
            else add(1,-1),imp[x]--,add(imp[x]+2,1);
        }else cout<<query(x+1)<<endl;
    }
    return 0;
}