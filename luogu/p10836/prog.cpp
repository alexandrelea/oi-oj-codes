#include <bits/stdc++.h>
using namespace std;
int n,m,k=0,h=0;
string a,b;
int main(){
    cin>>n>>m>>a>>b;
    for(int i=0;i<n;++i) k+=(b[i]=='#');
    for(int i=0;i<n;++i){
        if(a[i]!='#') continue;
        a[i]=('a'+h),++h;
        if((26-h)<=k) k-=(26-h),h=0;
    }
    cout<<a<<endl;
    return 0;
}