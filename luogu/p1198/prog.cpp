#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+10;
int n,m,d,ln,t;
int maxi[M*4];
struct task{
    char opt;
    int num;
    task(char opt='\0',int num=0):opt(opt),num(num){}
}a[M];
void update(int l,int r,int k,int ul,int ur,int u){
    if(l<=ul&&ur<=r){
        maxi[u]+=k;
        return;
    }
    int um=ul+(ur-ul)/2;
    if(l<=um) update(l,r,k,ul,um,u*2);
    if(r>um) update(l,r,k,um+1,ur,u*2+1);
    maxi[u]=max(maxi[u*2],maxi[u*2+1]);
}
int query(int l,int r,int ul,int ur,int u){
    if(l<=ul&&ur<=r) return maxi[u];
    int um=ul+(ur-ul)/2,ans=0;
    if(l<=um) ans=max(ans,query(l,r,ul,um,u*2));
    if(um<r) ans=max(ans,query(l,r,um+1,ur,u*2+1));
    return ans;
}
signed main(){
    cin>>m>>d;
    for(int i=1;i<=m;++i){
        cin>>a[i].opt>>a[i].num;
        if(a[i].opt=='A') ++n;
    }
    for(int i=1;i<=m;++i){
        if(a[i].opt=='A') ++ln,update(ln,ln,(t+a[i].num)%d,1,n,1);
        else t=query(ln-a[i].num+1,ln,1,n,1),cout<<t<<endl;
    }
    return 0;
}