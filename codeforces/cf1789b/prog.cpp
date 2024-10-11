// Codeforces 1789B - Serval and Inversion Magic
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int inve(int x){
    return n-x+1;
}
bool solve(){
    cin>>n>>s,s=" "+s;
    bool ok=0,vis=0;
    for(int i=1;i<=n/2;++i){
        if(s[i]!=s[inve(i)]){
            if(ok) return 0;
            vis=1;
        }else{
            if(vis) ok=1;
        }
    }
    return 1;
}
int main(){
    int _;
    cin>>_;
    while(_--) cout<<(solve()?"yes":"no")<<endl;
    return 0;
}