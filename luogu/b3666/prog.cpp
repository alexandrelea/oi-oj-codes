#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
stack<pair<ull,int>> a;
int n,ans=0;
ull v;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>v;
        while(!a.empty()&&a.top().first<=v) ans^=a.top().second,a.pop();
        a.push(make_pair(v,i)),ans^=i;
        cout<<ans<<endl;
    }
    return 0;
}