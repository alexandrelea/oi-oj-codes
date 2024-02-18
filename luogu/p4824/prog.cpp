#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],t[N];
int n,m,fl[N],h[N],ot,k,a[N];
int main(){
    cin>>(s+1)>>(t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=2,j=0;i<=m;++i){
        while(j&&t[i]!=t[j+1]) j=fl[j];
        if(t[i]==t[j+1]) ++j;
        fl[i]=j;
    }
    for(int i=1,j=0;i<=n;++i){
        while(j!=0&&s[i]!=t[j+1]) j=fl[j];
        if(s[i]==t[j+1]) ++j;
        h[i]=j,a[++k]=i;
        if(j==m) k-=m,j=h[a[k]];
    }
    for(int i=1;i<=k;++i) cout<<s[a[i]];
    return 0;
}