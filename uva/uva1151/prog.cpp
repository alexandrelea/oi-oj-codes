#include <bits/stdc++.h>
using namespace std;
int n,q,s[10][1010],w[10],x[1010],y[1010],fa[1010],ans=0x3f3f3f3f;
vector<pair<pair<int,int>,int>> gr;
int find(int u){
    return fa[u]=(fa[u]==u?u:find(fa[u]));
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return 0;
    return (fa[b]=a),1;
}
void solve(){
    gr.clear();
    ans=0x3f3f3f3f;
    cin>>n>>q;
    for(int i=1;i<=q;++i){
        cin>>s[i][0]>>w[i];
        for(int j=1;j<=s[i][0];++j) cin>>s[i][j];
    }
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j){
        int w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        gr.push_back(make_pair(make_pair(i,j),w));
    }
    sort(gr.begin(),gr.end(),[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)->bool {return a.second<b.second;});
    for(int stat=0;stat<(1<<q);++stat){
        int res=0,du=0;
        for(int i=1;i<=n;++i) fa[i]=i;
        for(int i=1;i<=q;++i){
            if(stat&(1<<(i-1))){
                for(int j=2;j<=s[i][0];++j) merge(s[i][j-1],s[i][j]);
                res+=w[i];
            }
        }
        if(res>ans) continue;
        for(int i=1;i<=n;++i) if(fa[i]==i) ++du;
        for(auto ie:gr){
            if(du==1) break;
            if(merge(ie.first.first,ie.first.second)){
                res+=ie.second;
                --du;
            }
        }
        if(du==1) ans=min(ans,res);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    int _,h=0;
    cin>>_;
    while(_--){
        if(h!=0) cout<<endl;
        solve();
        h=1;
    }
    return 0;
}