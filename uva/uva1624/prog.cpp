#include <iostream>
using namespace std;
void maintain(int caseno){
    int n,p,a[5010],b[5010],lasp;
    cin>>n>>p,lasp=p;
    for(int i=1;i<=p;i++) cin>>a[i]>>b[i];
    cout<<"Case #"<<caseno<<": ";
    // a list of continued numbers can be SELFLOOP.
    // two lists of continued numbers can be PASSING.
    // overall we can emu the link/emu the AB
    // we use the second method
    while(lasp){
        int fund=-1;
        // find the SELFLOOP
        for(int i=1;i<=p;i++){
            int x=a[i],y=b[i];
            if(a[i]==-1||b[i]==-1) continue;
            if(y<x) swap(x,y);
            bool ok=true;
            for(int j=1;j<=p;j++){
                if(j==i) continue;
                if((x<a[j]&&a[j]<y)||(x<b[j]&&b[j]<y)){
                    ok=false;
                    break;
                }
            }
            if(ok){
                fund=i;
                break;
            }
        }
        if(fund!=-1){
            // open the SELFLOOP
            cout<<"SELFLOOP "<<fund<<" ("<<a[fund]<<","<<b[fund]<<")"<<endl;
            a[fund]=b[fund]=-1;
            lasp--;
            continue;
        }
        int fnud=-1;
        for(int i=1;i<=p;i++){
            if(a[i]==-1||b[i]==-1) continue;
            for(int j=1;j<=p;j++){
                if(i==j||a[j]==-1||b[j]==-1) continue;
                int x=a[i],y=a[j];
                bool ok=true;
                if(y<x) swap(x,y);
                for(int k=1;k<=p;k++){
                    if(k==i||k==j) continue;
                    if((x<a[i]&&a[i]<y)||(x<b[i]&&b[i]<y)){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    fund=i,fnud=j;
                    break;
                }
                x=b[i],y=b[j],ok=true;
                if(y<x) swap(x,y);
                for(int k=1;k<=p;k++){
                    if(k==i||k==j) continue;
                    if((x<a[i]&&a[i]<y)||(x<b[i]&&b[i]<y)){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    fund=i,fnud=j;
                    break;
                }
            }
        }
        if(fund!=-1&&fnud!=-1){
            cout<<"PASSING "<<fund<<","<<fnud<<" ("<<a[fund]<<","<<b[fund]<<") ("<<a[fnud]<<","<<b[fnud]<<")"<<endl;
            a[fund]=b[fund]=a[fnud]=b[fnud]=-1,lasp-=2;
        }
        else break;
    }
    if(lasp==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) maintain(t);
    return 0;
}