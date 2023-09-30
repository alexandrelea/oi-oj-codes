#include <iostream>
#include <set>
#define int long long
using namespace std;
const int SIZE=1e5+10;
struct nodt{
    int l,r;
    mutable int v;
    nodt(const int &il,const int &ir,const int &iv):l(il),r(ir),v(iv){}
    bool operator<(const nodt &o)const{return l<o.l;}
};
set<nodt> odt;
int n,val[SIZE],wtf[SIZE];
typedef set<nodt>::iterator odti;
int lowbit(int x){
    return x&(-x);
}
void modify(int x,int d){
    int k=x;
    while(x<=n) val[x]+=d,wtf[x]+=d*k,x+=lowbit(x);
}
int summ(int x){
    int res=0,d=x;
    while(x) res+=val[x]*(d+1)-wtf[x],x-=lowbit(x);
    return res;
}
auto split(int x){
    if(x>n) return odt.end();
    auto it=--odt.upper_bound(nodt{x,0,0});
    if(it->l==x) return it;
    int l=it->l,r=it->r,v=it->v;
    odt.erase(it);
    odt.insert(nodt(l,x-1,v));
    return odt.insert(nodt(x,r,v)).first;
}
void assign(int l,int r,int v){
    odti itr=split(r+1),itl=split(l),it=itl;
    while(itl!=itr){
        modify(itl->l,abs(itl->v-v));
        modify(itl->r+1,-abs(itl->v-v));
        itl=odt.erase(itl);
    }
    odt.insert(nodt(l,r,v));
}
signed main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) odt.insert(nodt(i,i,i));
    while(m--){
        int o,l,r,v;
        cin>>o>>l>>r;
        if(o==1) cin>>v,assign(l,r,v);
        else cout<<summ(r)-summ(l-1)<<endl;
    }
    return 0;
}