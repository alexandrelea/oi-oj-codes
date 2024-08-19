#include <iostream>
#include <cstring>
using namespace std;
int n,s[15],f[15][15]={},p[15][15]={};
void out(int x,int y){
    if(x==y) cout<<"A"<<x;
    else{
        cout<<"(";
        out(x,p[x][y]);
        cout<<" x ";
        out(p[x][y]+1,y);
        cout<<")";
    }
}
int dp(int i,int j){
    if(~f[i][j]) return f[i][j];
    f[i][j]=0x3f3f3f3f;
    if(i==j) f[i][j]=0;
    else{
        for(int k=i;k<j;k++){
            if(f[i][j]>dp(i,k)+dp(k+1,j)+s[i-1]*s[k]*s[j]){
                f[i][j]=dp(i,k)+dp(k+1,j)+s[i-1]*s[k]*s[j];
                p[i][j]=k;
            }
        }
    }
    return f[i][j];
}
int main(){
    int _=0;
    while(cin>>n&&n!=0){
        memset(f,0xff,sizeof f);
        memset(p,0,sizeof p);
        for(int i=1;i<=n;i++) cin>>s[i-1]>>s[i];
        dp(1,n);
        cout<<"Case "<<(++_)<<": ";
        out(1,n);
        cout<<endl;
    }
    return 0;
}