// Codeforces 1907B - YetnotherrokenKeoard
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s,ans="";
    cin>>s;
    int n=s.length();
    stack<int> low,upp;
    for(int i=0;i<n;++i){
        if(s[i]=='b'){
            if(!low.empty()) ans[low.top()]='.',low.pop();
        }else if(s[i]=='B'){
            if(!upp.empty()) ans[upp.top()]='.',upp.pop();
        }else if(islower(s[i])) ans.append(1,s[i]),low.push(ans.size()-1);
        else if(isupper(s[i])) ans.append(1,s[i]),upp.push(ans.size()-1);
    }
    for(char ch:ans) if(ch!='.') cout<<ch;
    cout<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}