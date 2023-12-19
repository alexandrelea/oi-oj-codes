#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,a[51]={};
        cin>>n>>k;
        for(int i=1;i<=n;++i) a[i]=n-i+1;
        sort(a+1,a+k+2);
        for(int i=1;i<=n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}