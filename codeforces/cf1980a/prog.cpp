// CF1980A - Problem Generator
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        int n,m,pset[10]={},ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            char ch;
            cin>>ch;
            pset[ch-'A'+1]++;
        }
        for(int i=1;i<=7;++i) ans+=max(m-pset[i],0);
        cout<<ans<<endl;
    }
    return 0;
}
