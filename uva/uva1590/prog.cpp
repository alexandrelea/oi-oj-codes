#include <bits/stdc++.h>
using namespace std;
int m,to[330010][2],sub[330010],tot;
void insert(vector<int> ve){
    int u=0;
    for(int ie:ve){
        if(to[u][ie]==0) to[u][ie]=++tot,sub[u]++;
        u=to[u][ie];
    }
}
void solve(){
    memset(to,0,sizeof to);
    memset(sub,0,sizeof sub);
    tot=0;
    for(int i=1;i<=m;++i){
        int a,b,c,d;
        char e;
        cin>>a>>e>>b>>e>>c>>e>>d;
        vector<int> s;
        for(int i=7;i>=0;--i) s.push_back(!!(a&(1<<i)));
        for(int i=7;i>=0;--i) s.push_back(!!(b&(1<<i)));
        for(int i=7;i>=0;--i) s.push_back(!!(c&(1<<i)));
        for(int i=7;i>=0;--i) s.push_back(!!(d&(1<<i)));
        insert(s);
    }
    int u=0;
    vector<int> inet,mask;
    while(sub[u]==1){
        if(to[u][0]!=0) u=to[u][0],inet.push_back(0);
        else u=to[u][1],inet.push_back(1);
        mask.push_back(1);
    }
    while(inet.size()!=32) inet.push_back(0),mask.push_back(0);
    for(int i=0;i<4;++i){
        if(i!=0) cout<<".";
        int re=0;
        for(int j=0;j<8;++j) re<<=1,re|=inet[i*8+j];
        cout<<re;
    }
    cout<<endl;
    for(int i=0;i<4;++i){
        if(i!=0) cout<<".";
        int re=0;
        for(int j=0;j<8;++j) re<<=1,re|=mask[i*8+j];
        cout<<re;
    }
    cout<<endl;
}
int main(){
    while(cin>>m) solve();
    return 0;
}