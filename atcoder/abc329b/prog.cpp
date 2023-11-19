#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> S;
    int n,v;
    cin>>n;
    while(n--) cin>>v,S.insert(v);
    set<int>::iterator it=S.end();
    --it,--it;
    cout<<*it<<endl;
    return 0;
}