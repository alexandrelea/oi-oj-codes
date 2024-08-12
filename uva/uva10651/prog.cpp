// UVa10651 - Pebble Solitaire
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
map<string,int> memo;
int f(string stat){
    // cerr<<"f "<<stat<<endl;
    if(memo.count(stat)) return memo[stat];
    int ans=0;
    for(int i=0;i<stat.length();++i) if(stat[i]=='o') ++ans;
    for(int i=0;i<stat.length()-2;++i){
        if(stat[i]=='-'&&stat[i+1]=='o'&&stat[i+2]=='o'){
            string nstat=stat;
            nstat[i]='o',nstat[i+1]=nstat[i+2]='-';
            ans=min(ans,f(nstat));
        }
        if(stat[i]=='o'&&stat[i+1]=='o'&&stat[i+2]=='-'){
            string nstat=stat;
            nstat[i]=nstat[i+1]='-',nstat[i+2]='o';
            ans=min(ans,f(nstat));
        }
    }
    return memo[stat]=ans;
}
void solve(){
    string s;
    cin>>s;
    cout<<f(s)<<endl;
    // cerr<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}