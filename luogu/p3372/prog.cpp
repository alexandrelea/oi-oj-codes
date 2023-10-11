#include <iostream>
using namespace std;
const int SIZE=1e5+10;
int n,m,bit[SIZE],o,x,y,v;
auto eje=[](int x)->int {return x&(-x);};
int summ(int x){
    int ans=0;
    for(;x!=0;x-=eje(x)) ans+=bit[x];
    return ans;
}
void addd(int x,int v){
    for(;x<=n;x+=eje(x)) bit[x]+=v;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>o;
        addd(i,o);
    }
    for(int i=1;i<=n;i++) cout<<bit[i]<<" ";
    cout<<endl;
    while(m--){
        cin>>o>>x>>y;
        if(o==1) cin>>v,addd(x,v),addd(y,-v);
        else cout<<summ(y)-summ(x-1)<<endl;
    }
    return 0;
}