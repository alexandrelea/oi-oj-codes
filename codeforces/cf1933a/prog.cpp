// Codeforces 1993A - Turtle Puzzle: Rearrange and Negate
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int _,n,a;
    cin>>_;
    while(_--){
        cin>>n;
        int S=0;
        while(n--) cin>>a,S+=abs(a);
        cout<<S<<endl;
    }
    return 0;
}