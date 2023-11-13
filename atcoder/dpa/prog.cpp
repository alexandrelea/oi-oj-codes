#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,h[N],f[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i];
    f[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;++i){
        f[i]=min(f[i-2]+abs(h[i]-h[i-2]),f[i-1]+abs(h[i]-h[i-1]));
    }
    cout<<f[n]<<endl;
    return 0;
}