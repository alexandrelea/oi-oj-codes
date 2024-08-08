#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    while(cin>>n&&n){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=n;++i) cin>>x,pq.push(x);
        int ans=0;
        for(int i=1;i<n;++i){
            int a=pq.top();pq.pop();
            int b=pq.top();pq.pop();
            ans+=a+b,pq.push(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}