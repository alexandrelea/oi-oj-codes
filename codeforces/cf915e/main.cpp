#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast")
using namespace std;
const int SIZE=3e5+10;
int read(){
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}
void print(int x){
    if(x<0) putchar('-'),print(-x);
    if(x>=10) print(x/10);
    putchar(x%10+'0');
}
int n,q,ans=0;
struct nodt{
    int lf,rt;
    mutable bool val;
    nodt(int lf,int rt=-1,bool val=0):lf(lf),rt(rt),val(val){}
    bool operator<(const nodt &rhs)const{
        return lf<rhs.lf;
    }
};
set<nodt> wtf;
typedef set<nodt>::iterator iter;
iter split(int pos){
    iter it=wtf.lower_bound(nodt(pos));
    if(it!=wtf.end()&&it->lf==pos) return it;
    --it;
    int lf=it->lf,rt=it->rt;
    bool val=it->val;
    wtf.erase(it);
    wtf.insert(nodt(lf,pos-1,val));
    return wtf.insert(nodt(pos,rt,val)).first;
}
void assign(int lf,int rt,bool val){
    iter itr=split(rt+1),itl=split(lf);
    for(iter it=itl;it!=itr;++it) ans-=it->val*(it->rt-it->lf+1);
    wtf.erase(itl,itr);
    wtf.insert(nodt(lf,rt,val));
    ans+=(rt-lf+1)*val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    n=read(),q=read();
    wtf.insert(nodt(1,n,1));
    ans=n;
    while(q--){
        int l=read(),r=read(),k=read();
        assign(l,r,k-1);
        print(ans),putchar('\n');
    }
    return 0;
}
// 3 2 8 7
// 5 9 7 9
// 7 0 1 1
// 4 5 1 4