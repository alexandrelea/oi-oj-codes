#include <bits/stdc++.h>
using namespace std;
int n,l,cnt=0;
bool dfs(string cur){
    if(cnt++==n){
        int cl=cur.length();
        for(int i=0;i<cl;++i){
            if(i%64==0&&i!=0) cout<<endl;
            if(i%4==0&&i%64!=0) cout<<" ";
            cout<<cur[i];
        }
        cout<<endl<<cl<<endl;
        return 1;
    }
    for(char i='A';i<'A'+l;++i){
        string ext=cur,ecop;
        ext.push_back(i),ecop=ext;
        reverse(ecop.begin(),ecop.end());
        int eln=ecop.size();
        bool ok=1;
        for(int j=1;j*2<=eln;++j) if(ecop.substr(0,j)==ecop.substr(j,j)){
            ok=0;
            break;
        }
        if(ok) if(dfs(ext)) return 1;
    }
    return 0;
}
int main(){
    while(cin>>n>>l&&(n||l)) cnt=0,dfs("");
    return 0;
}