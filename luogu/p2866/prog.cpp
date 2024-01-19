#include <iostream>
#include <stack>
#define int long long
using namespace std;
const int size=80010;
signed main(){
    ios::sync_with_stdio(false);
    int n,h,ans=0;
    stack<int> stck;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h;
        while(!stck.empty()&&stck.top()<=h) stck.pop();
        ans+=stck.size(),stck.push(h);
    }
    cout<<ans<<endl;
    return 0;
}