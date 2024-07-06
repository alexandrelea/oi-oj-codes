#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x,a;
    cin>>n>>k>>x;
    for(int i=1;i<=n;++i){
        cin>>a;
        cout<<a<<" ";
        if(i==k) cout<<x<<" ";
    }
    return 0;
}