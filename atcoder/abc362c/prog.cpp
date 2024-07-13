#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,l[N],r[N],ls=0,rs=0,k[N];
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>l[i]>>r[i],ls+=l[i],rs+=r[i];
    if(ls<=0&&0<=rs){
        cout<<"Yes"<<endl;
        int sum=0,ans=0;
        for(int i=1;i<=n;++i){
            k[i]=(l[i]+r[i])/2;
            sum+=k[i];
        }
        if(sum<0){
            for(int i=1;i<=n&&sum;++i){
                if(k[i]-sum<=r[i]) k[i]-=sum,sum=0;
                else sum+=(r[i]-k[i]),k[i]=r[i];
            }
        }else{
            for(int i=1;i<=n&&sum;++i){
                if(k[i]-sum>=l[i]) k[i]-=sum,sum=0;
                else sum-=(k[i]-l[i]),k[i]=l[i];
            }
        }
        for(int i=1;i<=n;++i) cout<<k[i]<<" ",ans+=k[i];
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}