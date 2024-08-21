// LG2252 - [SHOI2002] 取石子游戏|【模板】威佐夫博弈
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    long double phi=(1.0+sqrtl(5))/2.0;
    while(cin>>n>>m){
        long long a=min(n,m),b=max(n,m);
        long double k=b-a;
        long long test=k*phi;
        cout<<(test!=a)<<endl;
    }
    return 0;
}