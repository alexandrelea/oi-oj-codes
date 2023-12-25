#include <bits/stdc++.h>
using namespace std;
int n,a[110],neg,pos,zro;
void solve(){
    cin>>n;
    neg=pos=zro=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]<0) ++neg;
        if(a[i]>0) ++pos;
        if(a[i]==0) ++zro;
    }
    if(neg%2==0){
        if(zro==0){
            cout<<1<<endl;
            for(int i=1;i<=n;++i){
                if(a[i]!=0){
                    cout<<i<<" "<<0<<endl;
                    return;
                }
            }
        }else cout<<0<<endl;
    }else{
        cout<<0<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}