#include <iostream>
#define int long long
using namespace std;
const int SIZE=3e4,EZIS=1e5;
int n,a[SIZE+10],ans=0;
int fenw[EZIS+10][4];
void add(int x,int v,int id){
    for(;x<=EZIS;x+=x&-x) fenw[x][id]+=v;
}
int sum(int x,int id){
    int ans=0;
    for(;x!=0;x-=x&-x) ans+=fenw[x][id];
    return ans;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        ans+=sum(a[i]-1,1);
        add(a[i],sum(a[i]-1,0),1);
        add(a[i],1,0);
    }
    cout<<ans<<endl;
    return 0;
}