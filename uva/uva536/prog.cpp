#include <bits/stdc++.h>
using namespace std;
string solve(string pre,string in){
    string ans="";
    if(pre.length()==1||pre.length()==0) return pre;
    int il=in.length(),pl=pre.length();
    for(int i=0;i<il;++i) if(in[i]==pre[0]){
        return solve(pre.substr(1,i),in.substr(0,i))+(1+i<pl?solve(pre.substr(1+i),in.substr(i+1)):"").append(1,pre[0]);
    }
}
int main(){
    string pre,in,post;
    while(cin>>pre>>in) cout<<solve(pre,in)<<endl;
    return 0;
}