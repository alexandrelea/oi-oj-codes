// 洛谷 p3865 - 【模板】ST 表 && RMQ 问题
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=(1<<17)+5;
int n,m,a[N];
int BIT1[N],BIT2[N];
int max(int x,int y){
    return x>y?x:y;
}
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int lb(int x){
    return x&-x;
}
void modif(int i,int v){
    for(int k=i;k<=n;k+=lb(k)) BIT1[k]=max(BIT1[k],v);
    for(int k=i;k>0;k-=lb(k)) BIT2[k]=max(BIT2[k],v);
    BIT2[0]=max(BIT2[0],v);
}
int query(int l,int r){
    int k,ans=max(a[l],a[r]);
    for(k=l;k+lb(k)<=r;k+=lb(k)) ans=max(ans,BIT2[k]);
    for(k=r;k-lb(k)>=l;k-=lb(k)) ans=max(ans,BIT1[k]);
    ans=max(ans,a[k]);
    return ans;
}
int main(){
    n=read(),m=read();
    int c=n;
    while(n-lb(n)!=0) n+=lb(n);
    for(int i=1;i<=c;++i){
        int v;
        v=read();
        modif(i,a[i]=v);
    }
    while(m--){
        int l,r;
        l=read(),r=read();
        cout<<query(l,r)<<'\n';
    }
    return 0;
}