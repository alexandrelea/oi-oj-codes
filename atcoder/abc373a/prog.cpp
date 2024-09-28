// Atcoder ABC373A - September
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    for(int i=1;i<=12;++i){
        string s;
        cin>>s;
        if(s.size()==i) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}