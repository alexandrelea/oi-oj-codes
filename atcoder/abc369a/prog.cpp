// Atcoder Beginner's Contest 369A - 369
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=-2*max(a,b);i<=2*max(a,b);++i){
        // i a b
        // a i b
        // a b i
        if(a-i==b-a||i-a==b-i||b-a==i-b) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}