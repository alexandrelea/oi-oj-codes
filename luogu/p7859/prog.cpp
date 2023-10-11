#include <iostream>
using namespace std;
int main(){
    int n,m,x[30],y[30],ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>x[i]>>y[i];
    for(int stat=0;stat<(1<<(n));stat++){
        bool ok=true;
        for(int i=1;i<=m;i++) if((stat&(1<<(x[i]-1)))&&(stat&(1<<(y[i]-1)))){
            ok=false;
            break;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}