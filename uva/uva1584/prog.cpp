#include <bits/stdc++.h>
using namespace std;
string mins(string a,string b){
    return a<b?a:b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int ls;
        string s;
        cin>>s,ls=s.length();
        string ans=s;
        for(int i=0;i<ls;++i) ans=mins(ans,s.substr(i)+s.substr(0,i));
        cout<<ans<<endl;
    }
    return 0;
}