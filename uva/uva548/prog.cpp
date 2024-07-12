#include <bits/stdc++.h>
using namespace std;
const int V=10000+10;
int inor[V],poor[V],ch[V][2],n;
bool read_list(int *a){
    string lin;
    if(!getline(cin,lin)) return false;
    stringstream ss(lin);
    n=0;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;
}
int build(int l1,int r1,int l2,int r2){
    if(l1>r1) return 0;
    int rooot=poor[r2],p=l1;
    while(inor[p]!=rooot) ++p;
    int cnt=p-l1;
    ch[rooot][0]=build(l1,p-1,l2,l2+cnt-1);
    ch[rooot][1]=build(p+1,r1,l2+cnt,r2-1);
    return rooot;
}
int best,besum;
void dfs(int u,int sum){
    sum+=u;
    if(!ch[u][0]&&!ch[u][1]){
        if(sum<besum||(sum==besum&&u<best)) best=u,besum=sum;
    }
    if(ch[u][0]) dfs(ch[u][0],sum);
    if(ch[u][1]) dfs(ch[u][1],sum);
}
int main(){
    while(read_list(inor)){
        read_list(poor);
        build(0,n-1,0,n-1);
        besum=0x3f3f3f3f;
        dfs(poor[n-1],0);
        cout<<best<<endl;
    }
    return 0;
}