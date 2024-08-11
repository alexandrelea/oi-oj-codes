// UVa10650 - Determinate Prime
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int pr[32005],pc,n,m;
bool vis[32005];
vector<pair<int,int>> ans;
int main(){
    for(int i=2;i<=32000;++i){
        if(!vis[i]) pr[++pc]=i;
        for(int j=1;j<=pc&&i*pr[j]<=32000;++j){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    for(int i=2;i<pc;){
        int fin=i;
        for(int j=i+1;j<pc;++j){
            if(pr[j]-pr[j-1]==pr[i]-pr[i-1]) fin=j;
            else break;
        }
        if(fin>i) ans.push_back({i-1,fin});
        i=fin+1;
    }
    while(cin>>n>>m&&(n||m)){
        if(n>m) swap(n,m);
        for(int i=0;i<ans.size();++i){
            if(pr[ans[i].first]>m) break;
            if(pr[ans[i].second]<n) continue;
            if(pr[ans[i].first]>=n&&pr[ans[i].second]<=m){
                cout<<pr[ans[i].first];
                for(int j=ans[i].first+1;j<=ans[i].second;++j) cout<<" "<<pr[j];
                cout<<endl;
            }
        }
    }
    return 0;
}