// Codeforces 1933E - Turtle vs. Rabbit Race: Optimal Trainings
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],aa[N],l,q;
int segmnt(int u,int n){
    return n*(u+1)-n*(n+1)/2;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],aa[i]=aa[i-1]+a[i];
    cin>>q;
    while(q--){
        int u,l,L,R,M0,M1,M;
        cin>>l>>u;
        L=l,R=n;
        while(R-L>=0){
            M=(R-L)/3;
            M0=L+M,M1=R-M;
            // L--M0--M1--R
            int f0=segmnt(u,aa[M0]-aa[l-1]),f1=segmnt(u,aa[M1]-aa[l-1]);
            // cerr<<L<<" "<<M0<<"("<<f0<<")"<<" "<<M1<<"("<<f1<<")"<<" "<<R<<endl;
            if(f0<f1) L=M0+1;
            else if(f0>f1) R=M1-1;
            else break;
        }
        cout<<L<<" ";
    }
    cout<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}