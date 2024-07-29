#include <bits/stdc++.h>
using namespace std;
int n,detr[6];
char cry[2][7][7];
string cryp[6];
void solve(){
    cin>>n;
    for(int k=0;k<2;++k){
        for(int i=1;i<=6;++i){
            for(int j=1;j<=5;++j) cin>>cry[k][i][j];
        }
    }
    for(int j=1;j<=5;++j){
        cryp[j]="";
        set<int> cryS[2];
        for(int k=0;k<2;++k) for(int i=1;i<=6;++i) cryS[k].insert(cry[k][i][j]);
        for(char a='A';a<='Z';++a) if(cryS[0].count(a)&&cryS[1].count(a)) cryp[j].push_back(a);
    }
    detr[5]=cryp[5].length();
    for(int i=4;i>=1;--i) detr[i]=detr[i+1]*cryp[i].length();
    if(n>detr[1]) return cout<<"NO"<<endl,void();
    for(int i=1;i<5;++i){
        int u=0;
        // cerr<<n<<" "<<detr[i+1]<<endl;
        while(n-detr[i+1]>0) n-=detr[i+1],++u;
        cout<<cryp[i][u];
    }
    cout<<cryp[5][n-1]<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve();
    return 0;
}