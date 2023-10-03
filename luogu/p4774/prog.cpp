#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef __int128_t lnt;
const int SIZE=1e5+10;
lnt exgcd(lnt a,lnt b,lnt &g,lnt &x,lnt &y){
    if(b==0) return x=1,y=0,g=a;
    else return exgcd(b,a%b,g,y,x),y-=a/b*x,g;
}
void maintain(){
    int n,m;
    lnt a[SIZE],p[SIZE],inl[SIZE],atk[SIZE];
    long long v;
    multiset<lnt> at;
    bool ok=true;

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v,a[i]=v;
    for(int i=1;i<=n;i++) cin>>v,p[i]=v;
    for(int i=1;i<=n;i++) cin>>v,inl[i]=v;
    for(int i=1;i<=m;i++){
        cin>>v;
        at.insert(v);
    }

    // attack (not consider x)
    for(int i=1;i<=n;i++){
        auto pt=at.upper_bound(a[i]);
        if(pt==at.begin()) atk[i]=*pt,at.erase(pt);
        else atk[i]=*(--pt),at.erase(pt);
        at.insert(inl[i]);
    }

    // find x (use exgcd)
    lnt b=0,c=1,lim=0;
    for(int i=1;i<=n;i++){
        lnt x=0,y=0,g;
        g=exgcd(c*atk[i],p[i],g,x,y);
        if((a[i]-b*atk[i])%g){
            ok=false;
            break;
        }
        lnt lc=c;
        c=c*p[i]/g;
        b=(((a[i]-b*atk[i])/g%c*lc%c*x%c+b)%c+c)%c;
        lim=max(lim,(lnt)ceil((double)(a[i])/atk[i]));
    }
    
    if(!ok){
        cout<<-1<<endl;
        return;
    }
    b=(b%c+c)%c;
    if(b<lim) b=b+c*(lnt)ceil((double)(lim-b)/c);
    v=b,cout<<v<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        maintain();
    }
    return 0;
}