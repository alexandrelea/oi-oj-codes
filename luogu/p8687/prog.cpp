#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,m,k,f[(1<<20)]={},a[105]={};
    cin>>n>>m>>k;
    for(int i=0;i<(1<<m);i++) f[i]=105;
    for(int i=0;i<n;i++) for(int j=0;j<k;j++){
        int t;
        cin>>t;
        a[i]=a[i]|(1<<(t-1));
    }
    f[0]=0;
    for(int i=0;i<n;i++) for(int j=0;j<(1<<m);j++){
        if(f[j]>100) continue;
        f[j|a[i]]=(f[j|a[i]]<f[j]+1)?f[j|a[i]]:f[j]+1;
    }
    if(f[(1<<m)-1]==105) cout<<-1<<endl;
    else cout<<f[(1<<m)-1]<<endl;
    return 0;
}