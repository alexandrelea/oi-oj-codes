// UVa 10125 - Sumsets
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,a[1005];
void solve(){
    set<int> s;
    map<int,int> m;
    for(int i=1;i<=n;++i) cin>>a[i],s.insert(a[i]),m[a[i]]=i;
    sort(a+1,a+n+1);
    for(int de=n;de>=1;--de){
        for(int ce=n;ce>=1;--ce){
            if(de==ce) continue;
            for(int be=n;be>=1;--be){
                if(de==be||ce==be) continue;
                int x=a[de]-a[ce]-a[be];
                if(x==a[de]||x==a[ce]||x==a[be]) continue;
                if(s.count(a[de]-a[ce]-a[be])){
                    cout<<a[de]<<endl;
                    // cerr<<a[de]<<"="<<a[m[a[de]-a[ce]-a[be]]]<<"+"<<a[be]<<"+"<<a[ce]<<","<<de<<"="<<m[a[de]-a[ce]-a[be]]<<"+"<<be<<"+"<<ce<<endl;
                    // break;
                    return;
                }
            }
        }
    }
    cout<<"no solution"<<endl;
}
signed main(){
    while(cin>>n&&n) solve();
    return 0;
}