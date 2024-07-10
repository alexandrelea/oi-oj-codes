#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int sum[N];
void build(int p){
    int v;
    cin>>v;
    if(v==-1) return;
    sum[p]+=v;
    build(p-1),build(p+1);
}
bool init(){
    int v;
    cin>>v;
    if(v==-1) return false;
    memset(sum,0,sizeof sum);
    int pos=N/2;
    sum[pos]=v;
    build(pos-1),build(pos+1);
    return true;
}
int main(){
    int kase=0;
    while(init()){
        int p=0;
        while(sum[p]==0) ++p;
        cout<<"Case "<<++kase<<":"<<endl<<sum[p++];
        while(sum[p]!=0) cout<<" "<<sum[p++];
        cout<<endl<<endl;
    }
    return 0;
}