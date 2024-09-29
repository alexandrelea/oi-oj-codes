// Codeforces 1542B - Plus and Multiply
// Code by Alexandre Lea
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b;
signed main(){
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--){
        cin>>n>>a>>b;
        if(a==1) cout<<((n%b==1||n==1||b==1)?"yes":"no")<<endl;
        else{
            bool ok=0;
            for(int i=1;i<=n;i*=a) if(i%b==n%b) ok=1;
            cout<<(ok?"yes":"no")<<endl;
        }
    }
    return 0;
}