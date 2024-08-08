#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    while(cin>>n&&n){
        m=floor(sqrt(n)+0.5);
        bool ok=(m*m==n);
        if(ok&&n) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}