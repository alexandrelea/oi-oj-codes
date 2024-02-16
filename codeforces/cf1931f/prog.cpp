#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,a[N],in[N],sum;
vector<int> gr[N];
queue<int> que;
bool solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) gr[i].clear();
    memset(in,0,sizeof(in)),sum=0;
    while(!que.empty()) que.pop();
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j) cin>>a[j];
        for(int j=3;j<=n;++j) gr[a[j-1]].push_back(a[j]),in[a[j]]++;
    }
    for(int i=1;i<=n;++i) if(in[i]==0) que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        ++sum;
        for(int v:gr[u]){
            if(--in[v]==0) que.push(v);
        }
    }
    return sum==n;
}
int main(){
    int t;
    cin>>t;
    while(t--) cout<<(solve()?"yes":"no")<<endl;
    return 0;
}