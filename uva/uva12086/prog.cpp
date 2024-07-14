#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,ohm[N+10],sum[N*4+10];
void build(int u,int ul,int ur){
    if(ul==ur) sum[u]=ohm[ul];
    else{
        int um=ul+((ur-ul)>>1);
        build(u*2,ul,um),build(u*2+1,um+1,ur);
        sum[u]=sum[u*2]+sum[u*2+1];
    }
}
void sett(int u,int ul,int ur,int cx,int cv){
    if(ul==ur) sum[u]=cv;
    else{
        int um=ul+((ur-ul)>>1);
        if(cx<=um) sett(u*2,ul,um,cx,cv);
        else sett(u*2+1,um+1,ur,cx,cv);
        sum[u]=sum[u*2]+sum[u*2+1];
    }
}
int gett(int u,int ul,int ur,int gl,int gr){
    if(gl<=ul&&ur<=gr) return sum[u];
    int um=ul+((ur-ul)>>1),ans=0;
    if(gl<=um) ans+=gett(u*2,ul,um,gl,gr);
    if(um<gr) ans+=gett(u*2+1,um+1,ur,gl,gr);
    return ans;
}
void solve(){
    for(int i=1;i<=n;++i) cin>>ohm[i];
    build(1,1,n);
    string op;
    while(cin>>op&&op!="END"){
        if(op=="S"){
            int x,v;
            cin>>x>>v;
            sett(1,1,n,x,v);
        }else if(op=="M"){
            int l,r;
            cin>>l>>r;
            cout<<gett(1,1,n,l,r)<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int _=0;
    while(cin>>n&&n){
        if(_) cout<<endl;
        cout<<"Case "<<(++_)<<":"<<endl;
        solve();
    }
    return 0;
}