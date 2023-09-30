#include <iostream>
using namespace std;
const int SIZE=1e6+10;
int n,q,c[SIZE],x,la=0;
void update(int x,int y){
    for(int i=x;i<=n;i+=(i&(-i))) c[i]+=y;
}
int query(int x){
    int ans=0;
    for(int i=x;i;i-=(i&(-i))) ans+=c[i];
    return ans;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x;
        update(i,x-la),la=x;
    }
    while(q--){
        int o,l,r,x;
        cin>>o;
        if(o==1) cin>>l>>r>>x,update(l,x),update(r+1,-x);
        else cin>>x,cout<<query(x)<<endl;
    }
    return 0;
}