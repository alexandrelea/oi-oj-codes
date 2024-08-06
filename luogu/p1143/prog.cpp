#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,o;
string s;
vector<int> ans;
int main(){
    cin>>n>>s>>m;
    for(int i=0;i<s.length();++i){
        o=o*n;
        if(isalpha(s[i])) o+=s[i]-'A'+10;
        else o+=s[i]-'0';
    }
    while(o) ans.push_back(o%m),o/=m;
    reverse(ans.begin(),ans.end());
    for(int ie:ans){
        if(ie>=10) cout<<(char)(ie-10+'A');
        else cout<<ie;
    }
    cout<<endl;
    return 0;
}