#include <iostream>
#include <string>
using namespace std;
const int SIZE=1e5+10;
string st;
int n,q;
int sum[4*SIZE];
void build(int co,int lef,int rih){
    if(lef==rih){
        sum[co]=1<<(st[lef]-'a');
        return;
    }
    int mid=lef+(rih-lef)/2;
    build(co*2,lef,mid);
    build(co*2+1,mid+1,rih);
    sum[co]=sum[co*2]|sum[co*2+1];
}
void modify(int co,int lef,int rih,int mx,char mv){
    if(lef==rih) return sum[co]=1<<(mv-'a'),void();
    int mid=lef+(rih-lef)/2;
    if(mx<=mid) modify(co*2,lef,mid,mx,mv);
    else modify(co*2+1,mid+1,rih,mx,mv);
    sum[co]=sum[co*2]|sum[co*2+1];
}
int query(int co,int lef,int rih,int ql,int qr){
    if(ql<=lef&&rih<=qr) return sum[co];
    int mid=lef+(rih-lef)/2,ans=0;
    if(ql<=mid) ans|=query(co*2,lef,mid,ql,qr);
    if(mid<qr) ans|=query(co*2+1,mid+1,rih,ql,qr);
    return ans;
}
int main(){
    cin>>st>>q;
    n=st.length(),st=" "+st;
    build(1,1,n);
    while(q--){
        int o,x,y;
        char ch;
        cin>>o>>x;
        if(o==1) cin>>ch,modify(1,1,n,x,ch);
        else cin>>y,cout<<__builtin_popcount(query(1,1,n,x,y))<<endl;
    }
    return 0;
}