#include <bits/stdc++.h>
using namespace std;
int _,n,m,k,binom[2005][2005],tabl[2005][2005];
int main(){
    cin>>_>>k;
    for(int i=0;i<=2000;++i){
        binom[i][0]=1%k;
        for(int j=1;j<i;++j) binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%k;
        binom[i][i]=1%k;
    }
    for(int i=1;i<=2000;++i){
        for(int j=1;j<=i;++j){
            tabl[i][j]=tabl[i-1][j]+tabl[i][j-1]-tabl[i-1][j-1];
            if(!binom[i][j]) ++tabl[i][j];
        }
        for(int j=i+1;j<=2000;++j) tabl[i][j]=tabl[i][i];
    }
    while(_--){
        cin>>n>>m;
        cout<<tabl[n][m]<<endl;
    }
    return 0;
}