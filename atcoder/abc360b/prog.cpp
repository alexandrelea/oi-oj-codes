#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    for(int w=1;w<s.length();++w){
        for(int c=0;c<w;++c){
            string rs="";
            for(int i=c;i<s.length();i+=w) rs.append(1,s[i]);
            if(rs==t){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}