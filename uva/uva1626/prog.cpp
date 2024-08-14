// UVa1626 - Brackets Sequence
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
int n,f[205][205];
string s;
bool mat(int p,int q){
    return (s[p]=='('&&s[q]==')')||(s[p]=='['&&s[q]==']');
}
void print(int i,int j){
    if(i>j) return;
    if(i==j){
        if(s[i]=='('||s[j]==')') cout<<"()";
        else cout<<"[]";
        return;
    }
    int ans=f[i][j];
    if(mat(i,j)&&ans==f[i+1][j-1]) cout<<s[i],print(i+1,j-1),cout<<s[j];
    else for(int k=i;k<j;++k) if(ans==f[i][k]+f[k+1][j]){
        print(i,k),print(k+1,j);
        break;
    }
}
void solve(){
    getline(cin,s);
    getline(cin,s),n=s.length(),s=" "+s;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i) f[i][i-1]=0,f[i][i]=1;
    for(int l=2;l<=n;++l){
        for(int i=1,j=l;j<=n;++i,++j){
            if(mat(i,j)) f[i][j]=min(f[i][j],f[i+1][j-1]);
            for(int k=i;k<j;++k) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        }
    }
    print(1,n);
    cout<<endl;
}
int main(){
    int _,__=0;
    cin>>_,cin.get();
    while(_--){
        if(__) cout<<endl;
        solve();
        __=1;
    }
    return 0;
}