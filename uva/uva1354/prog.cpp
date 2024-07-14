#include <bits/stdc++.h>
using namespace std;
double r,w[10],W[1100];
int s;
struct vive{
    double l,r;
    vive(double l=0,double r=0):l(l),r(r){}
};
vector<vive> la[1100];
bool vis[1100];
void dfs(int S){
    if(vis[S]) return;
    vis[S]=1;
    if((S&(S-1))==0) la[S].push_back(vive(0,0));
    else{
        for(int Sl=(S-1)&S;Sl>0;Sl=(Sl-1)&S){
            int Sr=Sl^S;
            dfs(Sl),dfs(Sr);
            double ll=W[Sr]/W[S],lr=W[Sl]/W[S];
            for(auto le:la[Sl]) for(auto re:la[Sr]){
                vive res=vive(max(le.l+ll,re.l-lr),max(re.r+lr,le.r-ll));
                if(res.l+res.r<r) la[S].push_back(res);
            }
        }
    }
}
int main(){
    int _;
    cin>>_;
    while(_--){
        memset(vis,0,sizeof vis);
        cin>>r>>s;
        for(int i=1;i<=s;++i) cin>>w[i];
        for(int i=0;i<(1<<s);++i){
            W[i]=0;
            for(int j=0;j<s;++j) if(i&(1<<j)) W[i]+=w[j+1];
            la[i].clear();
        }
        int sS=(1<<s)-1;
        double ans=-1.0/0.0;
        dfs(sS);
        for(vive ie:la[sS]) ans=max(ans,ie.l+ie.r);
        if(ans<0) cout<<-1<<endl;
        else cout<<fixed<<setprecision(8)<<ans<<endl;
    }
    return 0;
}