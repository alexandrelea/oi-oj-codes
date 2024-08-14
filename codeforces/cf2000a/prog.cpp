// CF2000A - Primary Task
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        string s;
        cin>>s;
        if(s.size()>=3&&s.substr(0,2)=="10"){
            int nu=stoi(s.substr(2));
            if(nu>=2&&s[2]!='0') cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }else cout<<"no"<<endl;
    }
    return 0;
}