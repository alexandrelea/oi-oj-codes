// Atcoder ABC373B - 1D Keyboard
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    map<char,int> pos;
    for(int i=1;i<=26;++i){
        char ch;
        cin>>ch;
        pos[ch]=i-1;
    }
    int ans=0,pox=pos['A'];
    for(char ch='A';ch<='Z';++ch) ans+=abs(pos[ch]-pox),pox=pos[ch];
    cout<<ans<<endl;
    return 0;
}