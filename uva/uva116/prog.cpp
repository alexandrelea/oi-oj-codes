#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,d[15][105],a[15][105],nex[15][105];
void solve(){
    memset(a,0,sizeof(a));
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin>>a[i][j];
    int ans=INF,first=0;
    for(int j=n-1;j>=0;--j){
        for(int i=0;i<m;++i){
            if(j==n-1) d[i][j]=a[i][j];
            else{
                int rows[3]={i,i-1,i+1};
                if(i==0) rows[1]=m-1;
                if(i==m-1) rows[2]=0;
                sort(rows,rows+3);
                d[i][j]=INF;
                for(int k=0;k<3;++k){
                    int v=d[rows[k]][j+1]+a[i][j];
                    if(v<d[i][j]) d[i][j]=v,nex[i][j]=rows[k];
                }
            }
            if(j==0&&d[i][j]<ans) ans=d[i][j],first=i;
        }
    }
    cout<<first+1;
    for(int i=nex[first][0],j=1;j<n;i=nex[i][j],++j) cout<<" "<<i+1;
    cout<<endl<<ans<<endl;
}
int main(){
    while(cin>>m>>n) solve();
    return 0;
}