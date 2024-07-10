#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int n,tage[N+10];
int main(){
    bool _=false;
    while(cin>>n){
        int h;
        if(_) cout<<endl;
        while(cin>>h&&h!=0){
            stack<int> s;
            int A=1,B=1;
            tage[1]=h;
            for(int i=2;i<=n;++i) cin>>tage[i];
            bool ok=true;
            while(B<=n){
                if(A==tage[B]) A++,B++;
                else if(!s.empty()&&s.top()==tage[B]) s.pop(),++B;
                else if(A<=n) s.push(A++);
                else{
                    ok=false;
                    break;
                }
            }
            cout<<(ok?"Yes":"No")<<endl;
        }
        _=true;
    }
    return 0;
}