#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1004535809;
int n,N,M;
ll a[1<<18],b[1<<18],A[1<<18],B[1<<18],h[1<<18],sum[100005],ww[1<<19],*e=ww+(1<<18);
int ans[100005];
ll ksm(ll a,int b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
char s[100005];
void ntt(ll *x,int n,int c){
    ll *a=x,*b=h,w,l,r;
    int i,j,k;
    for(i=n;i>1;i>>=1,swap(a,b)) for(j=0;j<n;j+=i) for(k=0;k<i;k+=2)
        b[j+(k>>1)]=a[j+k],b[j+(k>>1)+(i>>1)]=a[j+k+1];
    for(i=2;i<=n;i<<=1,swap(a,b)) for(w=0,k=0;k<(i>>1);++k,w+=n/i*c) for(j=0;j<n;j+=i){
        l=a[j+k],r=e[w]*a[j+(i>>1)+k]%mod;
        b[j+k]=(l+r)%mod,b[j+(i>>1)+k]=(l-r+mod)%mod;
    }
    for(int i=0;i<n;++i) x[i]=a[i];
}
void solve(int c){
    ntt(A,n,1),ntt(B,n,1);
    for(int i=0;i<n;++i) A[i]=A[i]*B[i]%mod;
    ntt(A,n,-1);
    int ni=ksm(n,mod-2);
    for(int i=M-1;i<N;++i) sum[i]=(sum[i]+A[i]*ni*c)%mod;
}
int main(){
    scanf("%s",s),N=strlen(s);
    for(int i=0;i<N;++i) a[i]=s[i]-'a'+1;
    scanf("%s",s),M=strlen(s);
    for(int i=0;i<M;++i) b[M-i-1]=(s[i]=='?'?0:s[i]-'a'+1);
    for(n=1;n<N+M;n<<=1);
    e[0]=e[-n]=1,e[1]=e[1-n]=ksm(3,(mod-1)/n);
    for(int i=2;i<n;++i) e[i-n]=e[i]=e[i-1]*e[1]%mod;
    for(int i=0;i<n;++i) A[i]=1,B[i]=b[i]*b[i]*b[i];
    solve(1);
    for(int i=0;i<n;++i) A[i]=a[i]*a[i],B[i]=b[i];
    solve(1);
    for(int i=0;i<n;++i) A[i]=a[i],B[i]=b[i]*b[i];
    solve(-2);
    for(int i=M-1;i<N;++i) if(!sum[i]) ans[++ans[0]]=i-M+1;
    for(int i=0;i<=ans[0];++i) cout<<ans[i]<<endl;
    return 0;
}