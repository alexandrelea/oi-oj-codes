#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,x;
int main(){
    cin>>n>>m>>x;
    if(m<n-1||m>(n-1)*(n-2)/2+1) cout<<-1<<endl;
    else{
        m-=n-1;
        for(int i=1;i<=n;++i){
            if(i!=x) cout<<i<<" "<<x<<endl;
        }
        if(m!=0) for(int i=2;i<n;++i){
            if(i==x) continue;
            for(int j=1;j<i;++j){
                if(j==x) continue;
                cout<<i<<" "<<j<<endl;
                --m;
                if(m==0) return 0; 
            }
        }
    }
    return 0;
}