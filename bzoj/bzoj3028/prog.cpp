// BZOJ 3028 - 食物
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const long long M=1'000'7;
int main(){
    long long n=0;
    char ch;
    ch=cin.get();
    while(!isalnum(ch)) ch=cin.get();
    while(isalnum(ch)) n=n*10+ch-'0',n%=M,ch=cin.get();
    cout<<n*(n+1)%M*(n+2)*1668%M<<endl;
    return 0;
}