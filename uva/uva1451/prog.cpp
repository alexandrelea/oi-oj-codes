// UVa 1451 - Average
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,l,a[N],s[N],p[N];
int cavg(int x1,int x2,int x3,int x4){
    return (s[x2]-s[x1-1])*(x4-x3+1)-(s[x4]-s[x3-1])*(x2-x1+1);
}
void solve(){
    char ch;
    cin>>n>>l;
    for(int i=1;i<=n;++i){
        cin>>ch;
        a[i]=ch-'0',s[i]=s[i-1]+a[i];
    }
    int aL=1,aR=l,i=1,j=1;
    for(int t=l;t<=n;++t){
        while(j-i>1&&cavg(p[j-2],t-l,p[j-1],t-l)>=0) --j;
        p[j++]=t-l+1;
        while(j-i>1&&cavg(p[i],t,p[i+1],t)<=0) ++i;
        int x=cavg(p[i],t,aL,aR);
        if(x>0||(x==0&&(aR-aL>t-p[i]))) aL=p[i],aR=t;
    }
    cout<<aL<<" "<<aR<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}