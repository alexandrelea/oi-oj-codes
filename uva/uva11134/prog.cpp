#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[5005];
vector<int> dim(vector<pair<pair<int,int>,int>> &re){
    vector<int> ans(n);
    sort(re.begin(),re.end());
    memset(vis,0,sizeof vis);
    for(auto ie:re){
        int xf=ie.first.first,xi=ie.first.second,nu=ie.second;
        bool ok=false;
        for(int i=xi;i<=xf;++i) if(!vis[i]){
            vis[i]=true,ans[nu]=i;
            ok=true;
            break;
        }
        if(!ok) throw string("IMPOSSIBLE");
    }
    return ans;
}
void solve(){
    int x0,y0,x1,y1;
    vector<pair<pair<int,int>,int>> x,y;
    vector<int> ans0,ans1;
    for(int i=1;i<=n;++i){
        cin>>x0>>y0>>x1>>y1;
        x.push_back(make_pair(make_pair(x1,x0),i-1));
        y.push_back(make_pair(make_pair(y1,y0),i-1));
    }
    try{
        ans0=dim(x),ans1=dim(y);
        for(int i=0;i<n;++i) cout<<ans0[i]<<" "<<ans1[i]<<endl;
    }catch(string err){
        cout<<err<<endl;
    }
}
int main(){
    while(cin>>n&&n) solve();
    return 0;
}