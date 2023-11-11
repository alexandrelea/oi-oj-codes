#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,s[10],ans=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>s[i],ans+=(s[i]>x?0:s[i]);
    cout<<ans<<endl;
    return 0;
}