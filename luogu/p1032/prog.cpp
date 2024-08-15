// LG1032 - 字串变换
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n=1;
string a,b,ine[7],oue[7];
set<string> vis;
bool dfs(int dep,string stat,int lim){
    // cerr<<dep<<" "<<stat<<" "<<lim<<endl;
    if(dep==lim) return stat==b;
    vis.insert(stat);
    int m=stat.length();
    for(int i=0;i<m;++i){
        for(int j=1;j<=n;++j){
            int k=ine[j].length();
            if(i+k<=m&&stat.substr(i,k)==ine[j]){
                string ext=stat.substr(0,i)+oue[j]+stat.substr(i+k);
                if(!vis.count(ext)&&dfs(dep+1,ext,lim)) return 1;
            }
        }
    }
    vis.erase(stat);
    return 0;
}
int main(){
    bool ok=0;
    string p,q;
    cin>>a>>b;
    while(cin>>ine[n]>>oue[n]) ++n;
    for(int lim=2;lim<=10;++lim) if(dfs(1,a,lim)){
        cout<<lim-1<<endl,ok=1;
        break;
    }
    if(!ok) cout<<"NO ANSWER!"<<endl;
    return 0;
}