// ATBC367B - Cut .0
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    while(s[s.length()-1]=='0') s.pop_back();
    if(s[s.length()-1]=='.') s.pop_back();
    cout<<s<<endl;
    return 0;
}