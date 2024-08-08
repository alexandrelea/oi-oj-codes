#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        int n,ans=0;
        set<int> s;
        queue<int> que;
        cin>>n;
        s.clear();
        while(n--){
            int x;
            cin>>x;
            while(s.count(x)&&!que.empty()) s.erase(que.front()),que.pop();
            que.push(x),s.insert(x);
            ans=max(ans,(int)que.size());
        }
        cout<<ans<<endl;
    }
    return 0;
}