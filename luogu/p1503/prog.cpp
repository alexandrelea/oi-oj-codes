#include <bits/stdc++.h>
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define rg register
using namespace std;
const int N=5e4+10;
int n,m,s[N],t;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    while(m--){
        rg char o;
        rg int x;
        cin>>o;
        if(o=='R') --t;
        else{
            cin>>x;
            if(o=='D') s[++t]=x;
            else{
                rg int l=0,r=n+1;
                for(int i=1;i<=t;++i){
                    if(s[i]<=x) l=max(l,s[i]);
                    if(s[i]>=x) r=min(r,s[i]);
                }
                cout<<(max(0,r-l-1))<<endl;
            }
        }
    }
    return 0;
}