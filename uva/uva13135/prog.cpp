#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        long long s,sq;
        bool ok=true;
        cin>>s;
        // if(s%2!=0) ok=false;
        sq=sqrt(1+8*s);
        if(sq*sq!=1+8*s) ok=false;
        if(ok) cout<<(sq-3)/2<<endl;
        else cout<<"No solution"<<endl;
    }
    return 0;
}
