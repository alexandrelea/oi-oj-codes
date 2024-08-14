// CF2000C - Numeric String Template
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m;
unordered_map<char,int> memo;
unordered_map<int,char> omem;
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>m;
    while(m--){
        memo.clear();
        omem.clear();
        string s;
        cin>>s;
        bool ok=s.size()==n;
        s=" "+s;
        for(int i=1;i<=n&&ok;++i){
            char ch=s[i];
            if(!memo.count(ch)) memo[ch]=a[i];
            else if(memo[ch]!=a[i]) ok=false;
        }
        for(int i=1;i<=n&&ok;++i){
            char ch=s[i];
            if(!omem.count(a[i])) omem[a[i]]=ch;
            else if(omem[a[i]]!=ch) ok=false;
        }
        cout<<(ok?string("yes"):string("no"))<<endl;
    }
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}