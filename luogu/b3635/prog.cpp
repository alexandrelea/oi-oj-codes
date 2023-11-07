#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+10;
int f[SIZE];
int main(){
    int n;
    cin>>n;
    memset(f,0x3f,sizeof(f)),f[0]=0;
    for(int i=1;i<=n;++i){
        f[i]=min(f[i-1]+1,f[i]);
        if(i-5>=0) f[i]=min(f[i-5]+1,f[i]);
        if(i-11>=0) f[i]=min(f[i-11]+1,f[i]);
    }
    cout<<f[n]<<endl;
    return 0;
}