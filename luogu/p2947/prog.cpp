#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,h[N],ob[N];
stack<pair<int,int>> st;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>h[i];
    for(int i=1;i<=n;++i){
        while(!st.empty()&&st.top().second<h[i]) ob[st.top().first]=i,st.pop();
        st.push(make_pair(i,h[i]));
    }
    for(int i=1;i<=n;++i) cout<<ob[i]<<endl;
    return 0;
}