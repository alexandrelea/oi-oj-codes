// WAed on 2023/10/2 21:44.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const static int SIZE=510;
int main(){
    int n,m;
    double alpha,h[SIZE],r[SIZE];
    double pjx[SIZE];
    double ans=0;
    cin>>n>>alpha;
    for(int i=0;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>r[i];
    double talp=tan(alpha),hh=h[0];
    for(int i=1;i<=n;i++){
        pjx[i]=hh/talp;
        hh+=h[i];
    }
    pjx[n+1]=hh/talp;
    for(int i=1;i<=n+1;i++) h[i]=pjx[i];
    reverse(h+1,h+n+2);
    reverse(r+1,r+n+1);
    h[0]=0;
    for(int i=0;i<n;i++){
        double dih=h[i+1]-h[i+2],dir=fabs(r[i+1]-r[i]);
        double pd=sqrt(dih*dih-dir*dir);
        double lfag=acos(dir/dih),rfag=acos((r[i+2]-r[i+1])/(h[i+2]-h[i+3]));
        ans+=pd*(r[i+1]+r[i+2]);
        if(i!=(n-1)) ans+=r[i+1]*r[i+1]*(rfag-lfag);
        else ans+=r[i+1]*r[i+1]*lfag;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
