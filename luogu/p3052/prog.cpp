#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int SIZE=3e5+10;
int n,a[20];
int f[SIZE],s[SIZE],ans,k;
int main(){
    memset(f,0x3f,sizeof(f)),f[0]=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))) s[i]+=a[j];
        }
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=i;j;j=(j-1)&i){
            if(s[j]>k) continue;
            f[i]=min(f[i],f[i-j]+1);
        }
    }
    cout<<f[(1<<n)-1]<<endl;
    return 0;
}