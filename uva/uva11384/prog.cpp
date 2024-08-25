// UVa11384 - Help is needed for Dexter
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int f(int n){
    return n==1?1:f(n/2)+1;
}
int main(){
    int n;
    while(cin>>n) cout<<f(n)<<endl;
    return 0;
}