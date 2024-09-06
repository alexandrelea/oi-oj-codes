// UVa 12103 - Leonardo's Notebook
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int vis[30],cnt[30];
void solve(){
    string B;
    cin>>B;
    for(int i=0;i<26;++i){
        if(vis[i]==0){
            int j=i,n=0;
            do{
                vis[j]=1;
                j=B[j]-'A';
                ++n;
            }while(j!=i);
            cnt[n]++;
        }
    }
    bool ok=1;
    for(int i=2;i<=26;++i,++i) if(cnt[i]%2==1) ok=0;
    cout<<(ok?"Yes":"No")<<endl;
}
int main(){
    int _;
    cin>>_;
    while(_--) solve(),memset(vis,0,sizeof(vis)),memset(cnt,0,sizeof(cnt));
    return 0;
}