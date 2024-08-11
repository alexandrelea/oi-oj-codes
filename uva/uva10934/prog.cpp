// UVa10934 - Dropping water balloons
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxk=1e2,A=63;
ull d[maxk+5][A+5];
int main(){
    memset(d,0,sizeof d);
    for(int i=1;i<=maxk;++i) for(int j=1;j<=A;++j) d[i][j]=d[i-1][j-1]+1+d[i][j-1];
    int k;
    ull n;
    while(cin>>k>>n&&k){
        int ans=-1;
        for(int i=1;i<=A;++i) if(d[k][i]>=n){
            ans=i;
            break;
        }
        if(ans<0) cout<<"More than "<<A<<" trials needed."<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}