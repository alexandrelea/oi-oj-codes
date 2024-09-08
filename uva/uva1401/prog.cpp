// UVa 1401 - Remember the Word
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int N=4000*100+5;
const int W=300005;
const int Z=20071027;
string word,piece;
int n,m,tot,ch[N][35],f[W];
bool vis[N];
void insert(){
    int u=1,l=piece.length();
    for(int i=0;i<l;++i){
        if(ch[u][piece[i]-'a']==0) ch[u][piece[i]-'a']=++tot;
        u=ch[u][piece[i]-'a'];
    }
    vis[u]=1;
}
// int dp(int p){
//     if(f[p]!=0) return f[p];
//     for(int i=p,u=1;i<m&&u!=0&&ch[u][word[i]-'a']!=0;++i){
//         u=ch[u][word[i]-'a'];
//         if(vis[u]) f[p]+=dp(i+1),f[p]%=Z;
//         if(i==m-1) ++f[p];
//     }
//     return f[p];
// }
int solve(){
    memset(ch,0,sizeof(ch));
    memset(vis,0,sizeof(vis));
    memset(f,0,sizeof(f));
    tot=1;
    cin>>n,m=word.length();
    while(n--) cin>>piece,insert();
    f[m]=1;
    for(int i=m-1;i>-1;--i){
        int u=1;
        for(int j=i;j<m;++j){
            if(ch[u][word[j]-'a']==0) break;
            u=ch[u][word[j]-'a'];
            if(vis[u]) f[i]+=f[j+1],f[i]+=Z,f[i]%=Z;
        }
    }
    return f[0];
}
int main(){
    int _=0;
    while(cin>>word) cout<<"Case "<<++_<<": "<<solve()<<endl;
    return 0;
}