// CF1985A - Creating Words
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        string a,b;
        cin>>a>>b;
        swap(a[0],b[0]);
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}