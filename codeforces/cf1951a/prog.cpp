#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    int n,c=0;
    vector<int> hf;
    cin>>n>>s;
    for(int i=0;i<n;++i) if(s[i]=='1') ++c,hf.push_back(i);
    if(c%2==1) cout<<"NO"<<endl;
    else if(c==0||c>2) cout<<"YES"<<endl;
    else if(c==2){
        if(hf[1]-hf[0]==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}