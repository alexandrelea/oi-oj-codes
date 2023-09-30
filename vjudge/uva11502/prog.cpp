#include <iostream>
#include <cmath>
using namespace std;
const int maxm=1e4+1;
const double g=9.8;
int main(){
    int _;
    cin>>_;
    while(_--){
        int n;
        double f[maxm]={};
        cin>>n;
        for(int i=1;i<maxm;i++) f[i]=-1e100;
        for(int i=1;i<=n;i++){
            int s,l,t,c;
            cin>>s>>l>>t>>c;
            for(int j=maxm-s-l-1;j>=0;j--){
                int tot=j+s+l;
                if(1.0*t/tot<g) continue;
                double time=1.0*l/c;
                double acc=t*(log(tot)-log(j+s))/c-time*g;
                f[tot]=max(f[tot],f[j]+acc);
            }
        }
        double ans=0;
        for(int i=0;i<maxm;i++) ans=max(ans,f[i]);
        cout<<round(ans)<<endl;
    }
    return 0;
}