// HDU 2065 - "红色病毒"问题
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
long long pw(int x,long long y){
    int ans=1;
    for(;y;y>>=1,x=x*x%100) if(y&1) ans=ans*x%100;
    return ans;
}
int main(){
    int _;
    while(cin>>_&&_){
        int __=0;
        while(_--){
            long long n;
            cin>>n;
            cout<<"Case "<<(++__)<<": "<<(pw(4,n-1)+pw(2,n-1))%100<<endl;
        }
        cout<<endl;
    }
    return 0;
}