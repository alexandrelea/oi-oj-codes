// UVa 701 - Burrows Wheeler Decoder
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
string ibwt(string s,int t){
    vector<string> dex(s.size());
    int n=s.size(),m=n;
    while(m--){
        for(int i=0;i<n;++i) dex[i]=s[i]+dex[i];
        sort(dex.begin(),dex.end());
    }
    return dex[t];
}
int main(){
    string s;
    int t;
    bool _=0;
    while(cin>>s>>t){
        if(s=="END"&&t==0) break;
        if(_) cout<<endl;
        cout<<ibwt(s,t-1)<<endl;
        _=1;
    }
    return 0;
}