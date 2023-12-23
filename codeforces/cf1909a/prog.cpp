#include <bits/stdc++.h>
using namespace std;
int n,x,y;
bool qr[4][4];
void solve(){
    int cnt=0,tnc=0;
    for(int i=1;i<=3;++i) for(int j=1;j<=3;++j) qr[i][j]=false;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        int xp=2,yp=2;
        if(x>0) ++xp;
        if(x<0) --xp;
        if(y>0) ++yp;
        if(y<0) --yp;
        qr[xp][yp]=1;
    }
    if(((!qr[3][1])&&(!qr[3][2])&&(!qr[3][3]))||((!qr[1][1])&&(!qr[2][1])&&(!qr[3][1]))||((!qr[1][1])&&(!qr[1][2])&&(!qr[1][3])||((!qr[1][3])&&(!qr[2][3])&&(!qr[3][3])))) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}