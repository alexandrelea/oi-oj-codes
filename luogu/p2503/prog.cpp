// LG2503 - [HAOI2006]均分数据
// Code by Alexanderia Lea
#include <bits/stdc++.h>
using namespace std;
const double td=0.99,eps=1e-6,ti=1e5;
int n,m,a[25],g[25],s[25],c[25];
double aver;
double lea(){
    double fin=0;
    for(int i=1;i<=m;++i) fin+=(s[i]-aver)*(s[i]-aver);
    return fin/(double)m;
}
int main(){
    default_random_engine rd(time(nullptr));
    uniform_real_distribution<double> hg(0,1+eps);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i],aver+=a[i];
    aver/=(double)m;
    for(int i=1;i<=n;++i){
        g[i]=rd()%m+1;
        s[g[i]]+=a[i];
    }
    double fina=1.0/0.0;
    while((double)clock()/CLOCKS_PER_SEC<0.75){
        double te=ti,ans=1.0/0.0;
        while(te>=eps){
            int u=rd()%(n)+1,v=rd()%(m)+1,w=g[u];
            if(v==w) continue;
            s[w]-=a[u],s[v]+=a[u],g[u]=v;
            double cans=lea();
            if(cans<ans||exp(-fabs(cans-ans)/te)>hg(rd)) ans=cans;
            else s[v]-=a[u],s[w]+=a[u],g[u]=w;
            fina=min(fina,ans);
            te*=td;
        }
        fina=min(fina,ans);
    }
    cout<<fixed<<setprecision(2)<<sqrt(fina)<<endl;
    return 0;
}