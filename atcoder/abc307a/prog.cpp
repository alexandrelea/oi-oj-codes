// ATBC307A - Weekly Records
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int s=0,x;
        for(int j=1;j<=7;++j) cin>>x,s+=x;
        cout<<s<<" ";
    }
    return 0;
}