#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,p;
    int ans,anslf,ansrt,year;
    deque<int> deq;
    while(cin>>y>>p){
        ans=anslf=ansrt=0;
        deq.clear();
        while(p--){
            cin>>year;
            while(!deq.empty()&&year-deq.front()>=y) deq.pop_front();
            deq.push_back(year);
            if((int)deq.size()>ans) ans=deq.size(),anslf=deq.front(),ansrt=deq.back();
        }
        cout<<ans<<" "<<anslf<<" "<<ansrt<<endl;
    }
    return 0;
}