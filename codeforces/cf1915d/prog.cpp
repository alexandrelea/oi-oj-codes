#include <bits/stdc++.h>
using namespace std;
map<char,int> cv={{'a',0},{'b',1},{'c',1},{'d',1},{'e',0}};
int n,vcnt=0;
string wd;
int bln[(int)(2e5+10)];
void solve(){
    cin>>n>>wd;
    vcnt=0;
    memset(bln,0,sizeof(bln));
    for(int i=0;i<n;++i){
        if(cv[wd[i]]==0) bln[i-1]=bln[i]=++vcnt;
    }
    for(int i=0;i<n;++i){
        cout<<wd[i];
        if(bln[i]!=bln[i+1]&&bln[i+1]!=0) cout<<".";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}