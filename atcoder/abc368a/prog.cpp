// ABC368A - Cut
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,k,a;
stack<int> euq;
queue<int> que;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a,euq.push(a);
    while(!euq.empty()) que.push(euq.top()),euq.pop();
    for(int i=1;i<=k;++i) que.push(que.front()),que.pop();
    while(!que.empty()) euq.push(que.front()),que.pop();
    while(!euq.empty()) cout<<euq.top()<<" ",euq.pop();
    cout<<endl;
    return 0;
}