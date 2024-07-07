#include <bits/stdc++.h>
using namespace std;
int n,fa[110];
double x[110],y[110];
struct efk{
    int u,v;
    double w;
    efk(int u=0,int v=0,double w=0):u(u),v(v),w(w){}
    bool operator<(const efk &rhs)const{
        return w<rhs.w;
    }
};
double dist(int u,int v){
    double Dx=x[u]-x[v],Dy=y[u]-y[v];
    return sqrt(Dx*Dx+Dy*Dy);
}
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
bool merge(int a,int b){
    a=find(a),b=find(b);
    return a==b?0:fa[a]=b;
}
void solve(){
    vector<efk> gr;
    cin>>n;
    double ans=0;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i],fa[i]=i;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) gr.push_back(efk(i,j,dist(i,j)));
    sort(gr.begin(),gr.end());
    for(auto edg:gr){
        if(merge(edg.u,edg.v)) ans+=edg.w;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
int main(){
    int _,__=1;
    cin>>_;
    while(_--){
        if(__==0) cout<<endl;
        solve();
        __=0;
    }
    return 0;
}