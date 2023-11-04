#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE=5e5+10;
typedef long long lnt;
lnt sq(lnt a){
    return a*a;
}
int main(){
    int n,m;
    lnt a[SIZE]={},ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+2*m+1);
    // for(int i=1;i<=2*m;i++) cout<<a[i]<<" ";
    for(int i=1;i<=m;i++) ans+=sq(a[i]+a[2*m-i+1]);
    cout<<ans<<endl;
    return 0;
}
