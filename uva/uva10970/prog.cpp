// UVa10970 - Big Chocolate
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int f(int x){
    if(x==1) return 0;
    return f(x/2)+f(x-x/2)+1;
}
int main(){
    int n,m;
    while(cin>>n>>m) cout<<min(f(n)+n*f(m),f(m)+m*f(n))<<endl;
    return 0;
}