#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,r;
    map<int,int> cnt;
    priority_queue<pair<int,int>> pq;
    vector<tuple<int,int,int>> ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r;
        cnt[r]++;
    }
    for(auto it:cnt) pq.push(make_pair(it.second,it.first));
    while(!pq.empty()){
        vector<pair<int,int>> get;
        vector<int> got;
        if(!pq.empty()) get.push_back(pq.top()),pq.pop();
        if(!pq.empty()) get.push_back(pq.top()),pq.pop();
        if(!pq.empty()) get.push_back(pq.top()),pq.pop();
        if(get.size()<3) break;
        for(auto it:get){
            if(it.first>1) pq.push(make_pair(it.first-1,it.second));
            got.push_back(it.second);
        }
        sort(got.begin(),got.end());
        ans.push_back(tuple<int,int,int>(got[0],got[1],got[2]));
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<(get<2>(it))<<" "<<(get<1>(it))<<" "<<(get<0>(it))<<" "<<endl;
    }
    return 0;
}