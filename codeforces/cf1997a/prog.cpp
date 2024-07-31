#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,l;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        bool ok=false;
        l=s.length();
        for(int i=1;i<l-1;++i){
            if(s[i]==s[i+1]){
                ok=true;
                cout<<s.substr(0,i+1)<<(char)(s[i]=='z'?s[i]-1:s[i]+1)<<s.substr(i+1)<<endl;
                break;
            }
        }
        if(!ok) cout<<(char)(s[0]=='z'?s[0]-1:s[0]+1)<<s<<endl;
    }
    return 0;
}