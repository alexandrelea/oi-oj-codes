#include <iostream>
#include <string>
using namespace std;
char hit(char a,char b){
    if(a=='X'){
        if(b=='X') return 'Y';
        if(b=='Y') return 'X';
        if(b=='Z') return 'Z';
    }else if(a=='Y'){
        if(b=='X') return 'X';
        if(b=='Y') return 'Y';
        if(b=='Z') return 'Y';
    }else if(a=='Z'){
        if(b=='X') return 'Z';
        if(b=='Y') return 'Y';
        if(b=='Z') return 'X';
    }
    throw 1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string st;
        int n;
        char f[110][110]={};
        cin>>st,n=st.length();
        st=" "+st;
        for(int i=1;i<=n;i++) f[i][i]=st[i];
        for(int ln=2;ln<=n;ln++) for(int i=1,j=i+ln-1;j<=n;i++,j++){
            for(int k=i;k<j;k++) f[i][j]=max(f[i][j],max(hit(f[i][k],f[k+1][j]),hit(f[k+1][j],f[i][k])));
        }
        cout<<f[1][n]<<endl;
    }
    return 0;
}