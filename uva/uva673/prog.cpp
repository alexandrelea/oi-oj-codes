#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.get();
    while(t--){
        string s;
        stack<char> stk;
        getline(cin,s);
        bool ok=true;
        for(int i=0;i<s.length();++i){
            if(s[i]=='('||s[i]=='[') stk.push(s[i]);
            else{
                if((s[i]==')'||s[i]==']')&&stk.empty()){
                    ok=false;
                    break;
                }else if((s[i]==')'&&stk.top()=='[')||(s[i]==']'&&stk.top()=='(')){
                    ok=false;
                    break;
                }else if(s[i]==')'||s[i]==']') stk.pop();
            }
        }
        if(!stk.empty()) ok=false;
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}