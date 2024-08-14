// LG3205 - [HNOI2010] 合唱队
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const int N=2005,M=19650827;
int n,a[N],f[N][N][2];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i][i][0]=1;
    for(int l=2;l<=n;++l){
        for(int i=1,j=l;j<=n;++i,++j){
            if(a[i]<a[i+1]) f[i][j][0]+=f[i+1][j][0];
            if(a[i]<a[j]) f[i][j][0]+=f[i+1][j][1];
            if(a[j]>a[i]) f[i][j][1]+=f[i][j-1][0];
            if(a[j]>a[j-1]) f[i][j][1]+=f[i][j-1][1];
            f[i][j][0]%=M,f[i][j][1]%=M;
        }
    }
    cout<<(f[1][n][0]+f[1][n][1])%M<<endl;
	return 0;
}

