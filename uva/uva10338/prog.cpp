#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact(ll x){
    return x==0?1:x*fact(x-1);
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--){
        string s;
        cin>>s;
        ll ans=fact(s.length()),alph[30]={};
        for(ll i=0;i<s.length();++i) alph[s[i]-'A']++;
        for(ll i=0;i<26;++i) if(alph[i]!=0) ans/=fact(alph[i]);
        cout<<"Data set "<<(++__)<<": "<<ans<<endl;
    }
    return 0;
}