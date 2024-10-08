// 洛谷 p2058 - [NOIP2016 普及组] 海港
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1<<17;
int n,cnt[N+1],tot;
int main(){
    cin>>n;
    queue<pair<int,unordered_set<int>>> tqu;
    while(n--){
        int t,k,x;
        unordered_set<int> co;
        cin>>t>>k;
        while(k--) cin>>x,co.insert(x);
        while(!tqu.empty()&&tqu.front().first<=t-86400){
            for(int ei:tqu.front().second) --cnt[ei],tot-=(cnt[ei]==0);
            tqu.pop();
        }
        tqu.push(make_pair(t,co));
        for(int ei:co) ++cnt[ei],tot+=(cnt[ei]==1);
        cout<<tot<<endl;
    }
    return 0;
}