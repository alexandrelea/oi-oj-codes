// ABC371A - Jiro
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> f[3];
    char ch;
    cin>>ch;
    if(ch=='<') f[1].push_back(0); else f[0].push_back(1);
    cin>>ch;
    if(ch=='<') f[2].push_back(0); else f[0].push_back(2);
    cin>>ch;
    if(ch=='<') f[2].push_back(1); else f[1].push_back(2);
    if(f[0].size()==1) cout<<'A'<<endl;
    if(f[1].size()==1) cout<<'B'<<endl;
    if(f[2].size()==1) cout<<'C'<<endl;
    return 0;
}