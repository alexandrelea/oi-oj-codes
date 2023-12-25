#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main(){
    int na,nb,nxt[N];
    char a[N],b[N];
    scanf("%s",a+1);
    scanf("%s",b+1);
    na=strlen(a+1),nb=strlen(b+1);
    for(int i=2,j=0;i<=nb;++i){
        while(j&&b[i]!=b[j+1]) j=nxt[j];
        if(b[i]==b[j+1]) ++j;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=na;++i){
        while(j&&a[i]!=b[j+1]) j=nxt[j];
        if(b[j+1]==a[i]) ++j;
        if(j==nb) cout<<i-nb+1<<endl,j=nxt[j];
    }
    for(int i=1;i<=nb;++i) cout<<nxt[i]<<" ";
    return 0;
}