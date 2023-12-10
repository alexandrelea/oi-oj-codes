#include<bits/stdc++.h>
using namespace std;
int a[10010],x,n,q,tot;
void solve(){
    cout<<"CASE# "<<(++tot)<<":"<<endl;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    while(q--){
        cin>>x;
        int fn=-1;
        for(int i=1;i<=n;++i) if(a[i]==x){
            fn=i;
            break;
        }
        if(fn==-1) cout<<x<<" not found"<<endl;
        else cout<<x<<" found at "<<fn<<endl;
    }
}
int main(){
    while(1){
        cin>>n>>q;
        if(n==0&&q==0) break;
        solve();
    }
    return 0;
}