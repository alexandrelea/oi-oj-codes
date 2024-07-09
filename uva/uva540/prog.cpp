#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ecks[1010];
queue<int> nuq,elq[1010];
map<int,int> wrek;
void solve(){
    for(int i=1;i<=n;++i){
        int t,h;
        cin>>t;
        ecks[i].clear();
        while(t--) cin>>h,ecks[i].push_back(h),wrek[h]=i;
        while(!elq[i].empty()) elq[i].pop();
    }
    while(!nuq.empty()) nuq.pop();
    string cmd;
    while(cin>>cmd&&cmd!="STOP"){
        int x;
        if(cmd=="ENQUEUE"){
            cin>>x;
            if(elq[wrek[x]].empty()) nuq.push(wrek[x]);
            elq[wrek[x]].push(x);
        }else if(cmd=="DEQUEUE"){
            cout<<elq[nuq.front()].front()<<endl;
            elq[nuq.front()].pop();
            if(elq[nuq.front()].empty()) nuq.pop();
        }
    }
}
int main(){
    int _=0;
    while(cin>>n&&n!=0) cout<<"Scenario #"<<(++_)<<endl,solve(),cout<<endl;
    return 0;
}