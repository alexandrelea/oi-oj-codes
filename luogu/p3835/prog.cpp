// 洛谷 P3835 - 【模板】可持久化平衡树
// Code by Alexandre Lea
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using __gnu_cxx::rope;
const int N=5'0000'5;
rope<int> *a[N];
int n,ver[N],tot,cnt;
int re(){
    int x=0,f=1;
    char ch=getchar();
    while(!isalnum(ch)) f=(ch=='-'?-1:1),ch=getchar();
    while(isalnum(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void wr(int x){
    if(x<0) putchar('-'),x=-x;
    char s[10];
    int t=0;
    while(x) s[++t]=x%10+'0',x/=10;
    while(t) putchar(s[t--]);
    puts("");
}
int main(){
    n=re();
    a[0]=new rope<int>;
    a[0]->push_back((int)0x80000001);
    a[0]->push_back((int)0x7fffffff);
    ver[0]=0;
    while(n--){
        ++cnt;
        int v=re(),o=re(),x=re();
        v=ver[v];
        if(o==1){
            a[++tot]=new rope<int>(*a[v]);
            ver[cnt]=tot;
            a[tot]->insert(lower_bound(a[tot]->begin(),a[tot]->end(),x)-a[tot]->begin(),x);
        }else if(o==2){
            a[++tot]=new rope<int>(*a[v]);
            ver[cnt]=tot;
            auto it=lower_bound(a[tot]->begin(),a[tot]->end(),x);
            if(*it==x) a[tot]->erase(it-a[tot]->begin(),1);
        }else if(o==3) ver[cnt]=v,wr(lower_bound(a[v]->begin(),a[v]->end(),x)-a[v]->begin());
        else if(o==4) ver[cnt]=v,wr(*(a[v]->begin()+x));
        else if(o==5) ver[cnt]=v,wr(*(--lower_bound(a[v]->begin(),a[v]->end(),x)));
        else ver[cnt]=v,wr(*upper_bound(a[v]->begin(),a[v]->end(),x));
    }
    return 0;
}