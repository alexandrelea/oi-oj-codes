// 洛谷 P4342 - [IOI1998] Polygon
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a[105],f[105][105],g[105][105];
char op[105];
int main(){
    cin>>n;
    memset(f,0xc0,sizeof(f));
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;++i){
        cin>>op[i]>>a[i];
        op[i+n]=op[i];
        f[i][i]=f[i+n][i+n]=a[i];
        g[i][i]=g[i+n][i+n]=a[i];
    }
    int ans=0xc0c0c0c0;
    vector<int> ace;
    for(int s=1;s<=n;++s){
        for(int l=2;l<=n;++l)
            for(int i=s,j=s+l-1;j<=s+n-1;++j,++i)
                for(int k=i;k<j;++k) if(op[k+1]=='t'){
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
                    g[i][j]=min(g[i][j],g[i][k]+g[k+1][j]);
                }else{
                    // f[i][j]=max(f[i][j],max(f[i][k]*f[k+1][j],max(g[i][k]*g[k+1][j],max(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                    // g[i][j]=min(g[i][j],min(f[i][k]*f[k+1][j],min(g[i][k]*g[k+1][j],min(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                    f[i][j]=max(f[i][j],f[i][k]*f[k+1][j]);
                    f[i][j]=max(f[i][j],g[i][k]*f[k+1][j]);
                    f[i][j]=max(f[i][j],f[i][k]*g[k+1][j]);
                    f[i][j]=max(f[i][j],g[i][k]*g[k+1][j]);
                    g[i][j]=min(g[i][j],g[i][k]*g[k+1][j]);
                    g[i][j]=min(g[i][j],f[i][k]*g[k+1][j]);
                    g[i][j]=min(g[i][j],g[i][k]*f[k+1][j]);
                    g[i][j]=min(g[i][j],f[i][k]*f[k+1][j]);
                }
        if(f[s][s+n-1]>ans) ans=f[s][s+n-1],ace.clear();
        if(f[s][s+n-1]==ans) ace.push_back(s);
    }
    cout<<ans<<endl;
    for(int ie:ace) cout<<ie<<" ";
    return 0;
}
// t -7 t 4 x 2 x 5 t -7 t 4 x 2 x 5