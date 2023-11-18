#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
string w[N],s[N],l[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>w[i];
        l[i]=s[i]=w[i];
        sort(s[i].begin(),s[i].end());
        sort(l[i].begin(),l[i].end(),greater<char>());
    }
    for(int i=1;i<=n;++i){
        bool ok=true;
        for(int j=1;j<=n;++j){
            if(i!=j&&s[i]>l[j]){
                ok=false;
                break;
            }
        }
        cout<<ok;
    }
    return 0;
}