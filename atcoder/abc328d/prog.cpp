#include <iostream>
using namespace std;
int main(){
    string s;
    char st[200010];
    int tost=0;
    cin>>s;
    for(int i=0;i<s.length();++i){
        st[++tost]=s[i];
        if(tost>=3&&st[tost]=='C'&&st[tost-1]=='B'&&st[tost-2]=='A') tost-=3;
    }
    for(int i=1;i<=tost;i++) cout<<st[i];
    return 0;
}