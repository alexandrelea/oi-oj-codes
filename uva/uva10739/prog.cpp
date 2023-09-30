#include <iostream>
#include <string>
using namespace std;
int main(){
    int t,tt=0;
    cin>>t;
    while(t--){
        string st;
        int n,f[1010][1010]={};
        cin>>st,n=st.length();    
        st=" "+st;
        for(int l=1;l<=n;l++) for(int i=1,j=i+l-1;j<=n;i++,j++){
            if(st[i]==st[j]) f[i][j]=f[i+1][j-1];
            else f[i][j]=min(f[i+1][j-1],min(f[i+1][j],f[i][j-1]))+1;
        }
        cout<<"Case "<<(++tt)<<": "<<f[1][n]<<endl;
    }
    return 0;
}