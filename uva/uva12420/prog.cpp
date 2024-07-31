#include <bits/stdc++.h>
#define fs(x) fixed<<setprecision(x)
using namespace std;
const double eps=1e-6;
int n,m,c,q;
double r[55][205],S[205][205];
bool wed[55][205];
double sqr(double x){
    return x*x;
}
int main(){
    cin>>n>>m>>c;
    for(int i=1,u,v;i<=c;++i){
        cin>>u>>v>>r[u][v];
        wed[u][v]=1;
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<i;++j){
            bool ok=false;
            double df=0;
            for(int k=1;k<=n;++k)
                if(wed[k][i]&&wed[k][j])
                    df+=sqr(r[k][i]-r[k][j]),ok=true;
            if(ok) S[i][j]=S[j][i]=1.0/(1.0+df);
        }
        S[i][i]=1.000;
    }
    while(cin>>q){
        vector<pair<double,int>> ans;
        for(int i=1;i<=m;++i){
            if(!wed[q][i]){
                double ph=0.0,qh=0.0;
                for(int j=1;j<=m;++j){
                    if(!wed[q][j]) continue;
                    ph+=r[q][j]*S[i][j];
                    qh+=S[i][j];
                }
                if(qh<=eps) ans.push_back(make_pair(-1,i));
                else ans.push_back(make_pair(ph/qh,i));
            }
        }
        sort(ans.begin(),ans.end(),greater<pair<double,int>>());
        int cnt=0;
        cout<<"Recommendations for user "<<q<<":"<<endl;
        for(auto ie:ans){
            if(cnt==10) break;
            ++cnt;
            cout<<ie.second<<" ";
            if(ie.first==-1) cout<<"-nan"<<endl;
            else cout<<fixed<<setprecision(3)<<ie.first<<endl;
        }
        cout<<endl;
    }
    return 0;
}