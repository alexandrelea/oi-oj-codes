// CF1985D - Manhattan Circle
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int Mi=0,Mj=0,mi=2e5+5,mj=2e5+5,n,m;
    vector<vector<char>> ma;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        ma.push_back(vector<char>());
        for(int j=0;j<m;++j){
            char ch;
            cin>>ch;
            ma[i].push_back(ch);
        }
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        if(ma[i][j]!='#') continue;
        Mi=max(Mi,i),mi=min(mi,i);
        Mj=max(Mj,j),mj=min(mj,j);
    }
    cerr<<mi<<" "<<Mi<<" "<<mj<<" "<<Mj<<endl;
    cout<<(Mi+mi)/2+1<<" "<<(Mj+mj)/2+1<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}