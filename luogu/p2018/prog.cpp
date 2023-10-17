#include <iostream>
#include <vector>
using namespace std;
int n;
int a[1010][1010],b[1010],d[1010],e[1010];
void p(int l,int r){
    if(l==r) return;
    int m=(l+r)/2;
    p(l,m),p(m+1,r);
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(d[i]<d[j]) e[k++]=d[i++];
        else e[k++]=d[j++];
    }
    while(i<=m) e[k++]=d[i++];
    while(j<=r) e[k++]=d[j++];
    for(int k=l;k<=r;k++) d[k]=e[k];
}
int f(int k,int n){
    int c[1010]={},l=0,i=0;
    if(n!=0&&a[k][0]==1) return 1;
    for(int j=1;j<=a[k][0];j++){
        if(a[k][j]!=n) i++,c[i]=f(a[k][j],k);
    }
    for(int x=1;x<=i;x++) d[x]=c[x];
    p(1,i),l=0;
    for(int j=i;j>=1;j--) if(l<d[j]+i-j) l=d[j]+i-j;
    return l+1;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int k;
        cin>>k;
        a[i][++a[i][0]]=k;
        a[k][++a[k][0]]=i;
    }
    int minn=0x3f3f3f3f;
    for(int i=1;i<=n;i++) minn=min(minn,b[i]=f(i,0));
    cout<<minn<<endl;
    for(int i=1;i<=n;i++) if(b[i]==minn) cout<<i<<" ";
    return 0;
}