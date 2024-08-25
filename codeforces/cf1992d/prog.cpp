// CF1992D - Test of Love
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,m,k,lL=0,nL[2'00'005]={};
string a;
bool solve(){
    cin>>n>>m>>k>>a;
    a="L"+a+"L";
    memset(nL,0,sizeof nL),lL=0;
    for(int i=1;i<=n+1;++i){
        if(a[i]=='L') nL[lL]=i,lL=i;
    }
    int p=0;
    while(p<=n+1){
        if(a[p]=='C'||k<0) return false;
        else if(p==n+1) return true;
        else if(a[p]=='W') ++p,--k;
        else if(a[p]=='L'){
            if(nL[p]-p<=m) p=nL[p];
            else{
                bool ok=0;
                for(int i=m;i>=1;--i) if(a[p+i]=='W'){
                    ok=1,p+=i;
                    break;
                }
                if(!ok) return false;
            }
        }
    }
    return true;
}
int main(){
    int _;
    cin>>_;
    while(_--) cout<<(solve()?string("yes"):string("no"))<<endl;
    return 0;
}