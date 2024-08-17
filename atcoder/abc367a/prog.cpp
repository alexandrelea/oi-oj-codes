// ATBC367A - Shout Everyday
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,aw[24];
    cin>>a>>b>>c;
    for(int i=c;i!=b;++i,i%=24) aw[i]=1;
    cout<<(aw[a]?"Yes":"No")<<endl;
    return 0;
}