// 洛谷 p5490 - 扫描线 & 矩形面积并
// Code by Alexandre Lea
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE=2e5+10;
struct scan{
    int l,r,h,d;
    scan(int l=0,int r=0,int h=0,int d=0):l(l),r(r),h(h),d(d){}
    bool operator<(const scan &o)const{return h<o.h;};
}line[SIZE];
int n,m,cnt[SIZE*4],sum[SIZE*4],a[SIZE];
void pushup(int l,int r,int x){
    if(cnt[x]) sum[x]=a[r+1]-a[l];
    else if(l==r) sum[x]=0;
    else sum[x]=sum[x<<1]+sum[x<<1|1];
}
void update(int l,int r,int x,int d,int sl,int sr){
    if(sl<=l&&r<=sr){
        cnt[x]+=d,pushup(l,r,x);
        return;
    }
    int mid=(l+r)>>1;
    if(sl<=mid) update(l,mid,x<<1,d,sl,sr);
    if(sr>mid) update(mid+1,r,x<<1|1,d,sl,sr);
    pushup(l,r,x);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x0,y0,x1,y1;
        cin>>x0>>y0>>x1>>y1;
        a[m]=x0,line[m++]=scan(x0,x1,y0,1);
        a[m]=x1,line[m++]=scan(x0,x1,y1,-1);
    }
    sort(a,a+m),sort(line,line+m);
    m=unique(a,a+m)-a;
    unsigned long long ans=0;
    for(int i=0;i<(n*2);i++){
        int l=lower_bound(a,a+m,line[i].l)-a;
        int r=lower_bound(a,a+m,line[i].r)-a;
        update(0,m-1,1,line[i].d,l,r-1);
        ans+=(unsigned long long)sum[1]*(line[i+1].h-line[i].h);
    }
    cout<<ans<<endl;
    return 0;
}