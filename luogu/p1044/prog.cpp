#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    __int128_t binom[40][40]={};
    cin>>n;
    binom[0][0]=1;
    for(int i=1;i<=n*2;i++){
        binom[i][0]=1;
        for(int j=1;j<=i;j++) binom[i][j]=binom[i-1][j]+binom[i-1][j-1];
        binom[i][i]=1;
    }
    cout<<(long long)(binom[2*n][n]/(n+1))<<endl;
    return 0;
}