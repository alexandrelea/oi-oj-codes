#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    char c;
    int h=3;
    while(h--){
        cin>>c;
        if(c=='R'||c=='M') s.append(1,c);
    }
    if(s=="RM") cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}