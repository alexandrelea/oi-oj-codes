#include <bits/stdc++.h>
using namespace std;
int n,k,b[10];
void solve(){
    int prod=1;
    bool flag=true;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>b[i],prod*=b[i];
        if(prod>2023) flag=false;
    }
    if(flag&&prod!=0&&2023%prod==0&&2023>=prod&&k!=0){
        cout<<"yes"<<endl<<2023/prod;
        for(int i=1;i<k;++i) cout<<" 1";
        cout<<endl;
    }else cout<<"no"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}