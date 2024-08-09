#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long
#define eps 1e-6
using namespace std;
const int N=1e5+10;
int n,top,sum,ans;
struct why{
    int t,w,v;
}c[N],a[N];
int cal(int p,int cnt,int t,int sum){
    int a=-1,b=t-p,c=cnt-sum+t*p;
    int delta=b*b-4*a*c;
    if(delta<0) return -1;
    int x=(-double(b)-sqrt(delta))/(2.0*double(a))+eps;
    if(a*x*x+b*x+c<0) return -1;
    return x;
}
int check(){
    int cnt=0,p=1,minn,sum;
    for(int i=1;i<=top;i++){
        minn=0x3f3f3f3f,sum=0;
        for(int j=i;j<=top;j++){
            sum+=a[j].w;
            minn=min(cal(p,cnt,a[j].t-a[i-1].t,sum),minn);
        }
        if(minn<0) return 0;
        p+=minn;
        cnt+=p*(a[i].t-a[i-1].t-minn)-a[i].w;
    }
    return 1;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].t>>c[i].w>>c[i].v;
    }
    sort(c+1,c+n+1,[](why a,why b)->bool {return a.t<b.t;});
    for(int s=1;s<(1<<n);s++){
        top=sum=0;
        for(int i=1;i<=n;i++) if(s&(1<<(i-1))) a[++top]=c[i],sum+=c[i].v;
        if(check()) ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}