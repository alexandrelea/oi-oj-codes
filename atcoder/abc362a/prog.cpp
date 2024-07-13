#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,g,b,ans=0x3f3f3f3f;
    string s;
    cin>>r>>g>>b>>s;
    if(s=="Red") ans=min(g,b);
    else if(s=="Green") ans=min(r,b);
    else ans=min(r,g);
    cout<<ans<<endl;
    return 0;
}