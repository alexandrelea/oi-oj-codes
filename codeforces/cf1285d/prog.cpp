#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
vector<int> a;
int solve(vector<int> w,int k){
    if(w.size()==0||k<0) return 0;
    vector<int> w1,w2;
    for(int ie:w){
        if(ie&(1<<k)) w1.push_back(ie);
        else w2.push_back(ie);
    }
    if(w1.size()==0||w2.size()==0) return solve(w1,k-1)+solve(w2,k-1);
    else return (1<<k)+min(solve(w1,k-1),solve(w2,k-1));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int v;
        cin>>v;
        a.push_back(v);
    }
    cout<<solve(a,30)<<endl;
    return 0;
}