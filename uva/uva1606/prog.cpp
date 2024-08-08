#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,col[N];
struct point{
    int x,y;
    double rad;
    point(int x=0,int y=0):x(x),y(y),rad(0){}
}pt[N];
bool instr(point a,point b){
    return a.x*b.y-a.y*b.x>=0;
}
int solve(int nu){
    vector<point> ref;
    for(int i=1;i<=n;++i) if(i!=nu){
        point p=point(pt[i].x-pt[nu].x,pt[i].y-pt[nu].y);
        if(col[i]) p.x=-p.x,p.y=-p.y;
        p.rad=atan2((double)p.y,(double)p.x);
        ref.push_back(p);
    }
    sort(ref.begin(),ref.end(),[](point a,point b)->bool {return a.rad<b.rad;});
    int lp=0,rp=0,cnt=2,ans=0,m=ref.size();
    while(lp<m){
        if(rp==lp) ++cnt,rp=(rp+1)%m;
        while(rp!=lp&&instr(ref[lp],ref[rp])) rp=(rp+1)%m,++cnt;
        --cnt,++lp,ans=max(ans,cnt);
    }
    return ans;
}
int main(){
    while(cin>>n&&n){
        for(int i=1;i<=n;++i) cin>>pt[i].x>>pt[i].y>>col[i];
        int ans=0;
        for(int i=1;i<=n;++i) ans=max(ans,solve(i));
        cout<<ans<<endl;
    }
    return 0;
}