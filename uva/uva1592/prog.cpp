#include <bits/stdc++.h>
using namespace std;
int n,m,tot;
int tabl[10010][15];
map<string,int> conv;
int erec(string ss){
    if(!conv.count(ss)) conv[ss]=++tot;
    return conv[ss];
}
void solve(){
    tot=0;
    conv.clear();
    cin.get();
    for(int i=1;i<=n;++i){
        string ss,wd="";
        getline(cin,ss);
        ss+=",";
        int k=0;
        for(int j=0;j<ss.length();++j){
            if(ss[j]!=',') wd.append(1,ss[j]);
            else tabl[i][++k]=erec(wd),wd="";
        }
    }
    for(int i=1;i<=n;++i,cerr<<endl) for(int j=1;j<=m;++j) cerr<<tabl[i][j]<<" ";
    bool ok=false;
    int ar1,ar2,ac1,ac2;
    for(int c1=1;c1<=m&&!ok;++c1) for(int c2=c1+1;c2<=m&&!ok;++c2){
        map<pair<int,int>,int> rerow;
        int r1,r2;
        for(int r=1;r<=n&&!ok;++r){
            pair<int,int> nwe=make_pair(tabl[r][c1],tabl[r][c2]);
            if(rerow.count(nwe)) ok=true,r1=rerow[nwe],r2=r;
            else rerow[nwe]=r;
        }
        if(ok) ar1=r1,ar2=r2,ac1=c1,ac2=c2;
    }
    if(!ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl<<ar1<<" "<<ar2<<endl<<ac1<<" "<<ac2<<endl;
}
int main(){
    while(cin>>n>>m) solve();
    return 0;
}