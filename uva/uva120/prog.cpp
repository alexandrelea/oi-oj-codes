#include <bits/stdc++.h>
using namespace std;
int n,a[35],t[35];
vector<int> ans;
void flip(int p){
    for(int i=1;i<=p;++i) t[p-i+1]=a[i];
    for(int i=1;i<=p;++i) a[i]=t[i];
    ans.push_back(n-p+1);
}
bool sted(){
    for(int i=2;i<=n;++i) if(a[i-1]>a[i]) return 0;
    return 1;
}
void solve(string l){
    stringstream sin(l);
    n=0;
    while(sin>>a[++n]);
    --n;
    ans.clear();
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
    cout<<endl;
    if(sted()) return cout<<0<<endl,void();
    int p=1;
    for(int j=2;j<=n;++j) if(a[j]<a[p]) p=j;
    flip(p);
    for(int i=2;i<=n;++i){
        if(sted()) break;
        int p=i;
        for(int j=i+1;j<=n;++j) if(a[j]<a[p]) p=j;
        if(p==i) continue;
        flip(p),flip(p-i+1),flip(p);
    }
    for(int ie:ans) cout<<ie<<" ";
    cout<<"0"<<endl;
}
int main(){
    string s;
    while(getline(cin,s)) solve(s);
    return 0;
}