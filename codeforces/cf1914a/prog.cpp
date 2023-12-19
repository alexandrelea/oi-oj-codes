#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cnt[26]={},ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            char ch;
            cin>>ch;
            cnt[ch-'A']++;
        }
        for(int i=0;i<26;++i){
            if(cnt[i]>=i+1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}