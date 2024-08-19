#include <bits/stdc++.h>
using namespace std;
/**
 * The problem gives 2 requests:
 *  a_x+a_{x+1}+...+a_{x+y}>c
 *  a_x+a_{x+1}+...+a_{x+y}<c
 * 
 * We can use S_x stand for a_1+a_2+...+a_x, then we can revert requests into:
 *  s_{x+y}-s_{x-1}>c
 *  s_{x+y}-s_{x-1}<c
 * 
 * because of the integer, we can convert above into two request
 *  s_{x+y}-s_{x-1}>=c+1
 *  s_{x+y}-s_{x-1}<=c-1
 * 
 * and into integer requests
 *  s_{x-1}-s_{x+y}<=(-c-1) stand for gt
 *  s_{x+y}-s_{x-1}<=c-1 stand for lt
*/
const int INF=0x3f3f3f3f,SIZE=110;
int main(){
    int n,m,ans[SIZE];
    vector<pair<int,int>> edge[SIZE];
    while(cin>>n&&n!=0){
        cin>>m;
        for(int i=1;i<=m;i++){
            int x,y,c;
            string rq;
            cin>>x>>y>>rq>>c;
            if(rq=="gt") edge[x+y+1].push_back(make_pair(x,-c-1));
            if(rq=="lt") edge[x].push_back(make_pair(x+y+1,c-1));
        }
        ans[0]=0;
        for(int i=1;i<=n+1;i++) edge[0].push_back({i,0}),ans[i]=0x3f3f3f3f;
        int itr=0,upd=0;
        do{
            upd=0;
            for(int u=0;u<=n+1;u++){
                for(auto edg:edge[u]){
                    int v=edg.first,w=edg.second;
                    if(ans[v]>ans[u]+w) upd++,ans[v]=ans[u]+w;
                }
            }
        }while(upd&&(itr++)<n);
        if(upd) cout<<"successful conspiracy"<<endl;
        else cout<<"lamentable kingdom"<<endl;
        for(int i=0;i<=n+1;i++) edge[i].clear(),ans[i]=0;
    }
    return 0;
}