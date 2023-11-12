#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int N=1e5+10;
crope now,x[N];
int t,p,V;
signed main(){
    cin>>t;
    while(t--){
        char opt;
        cin>>opt;
        switch(opt){
        case 'T':
            char qc;
            cin>>qc;
            now.insert(p,qc);
            p++,x[++V]=now;
            break;
        case 'U':
            int qi;
            cin>>qi;
            now=x[V-qi],x[++V]=now;
            break;
        case 'Q':
            int qj;
            cin>>qj;
            putchar(now.at(qj-1));
            puts("");
        }
    }
    return 0;
}