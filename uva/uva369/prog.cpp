// UVa369 - Combinations
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int pct[25];
void uniq(int x,int v){
    for(int i=0;i<25&&x!=1;++i) while(x%pr[i]==0) pct[i]+=v,x/=pr[i];
}
void fact(int x,int v){
    for(int i=2;i<=x;++i) uniq(i,v);
    // for(int i=0;i<25;++i) if(pct[i]) cout<<pr[i]<<"^"<<pct[i]<<" ";
    // cout<<endl;
}
int main(){
    int n,m;
    while(cin>>n>>m&&n&&m){
        memset(pct,0,sizeof pct);
        fact(n,1),fact(m,-1),fact(n-m,-1);
        vector<int> ans={1};
        for(int i=0;i<25;++i){
            for(int j=1;j<=pct[i];++j){
                for(int &ie:ans) ie*=pr[i];
                for(size_t i=0;i<ans.size();++i){
                    if(i+1==ans.size()&&ans[i]>=10) ans.emplace_back(0);
                    ans[i+1]+=ans[i]/10,ans[i]%=10;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<n<<" things taken "<<m<<" at a time is ";
        for(int ie:ans) cout<<ie;
        cout<<" exactly."<<endl;
    }
    return 0;
}