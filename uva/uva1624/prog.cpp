#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
void maintain(int caseno){
    int n,p,a[5010],b[5010],lasp,cnt=0;
    set<int> se;
    map<int,int> cov;

    cin>>n>>p,lasp=p;
    for(int i=1;i<=p;i++) cin>>a[i]>>b[i],se.insert(a[i]),se.insert(b[i]);
    for(auto it:se) cov[it]=cnt++;
    for(int i=1;i<=p;i++) a[i]=cov[a[i]],b[i]=cov[b[i]];

    // a list of continued numbers can be SELFLOOP.
    // two lists of continued numbers can be PASSING.
    // overall we can emu the link/emu the AB
    // we use the second method --- ?
    while(lasp){
        // for(int i=1;i<=p;i++) cout<<a[i]<<" "<<b[i]<<endl;
        int fna=-1,fnb=-1;
        for(int i=1;i<=p;i++){
            if(a[i]==-1||b[i]==-1) continue;
            if((a[i]+1)%cnt==b[i]||(b[i]+1)%cnt==a[i]){
                fna=i;
                break;
            }
        }
        for(int i=1;i<=p;i++){
            if(a[i]==-1||b[i]==-1) continue;
            bool fnd=false;
            for(int j=1;j<=p;j++){
                if(i==j||a[j]==-1||b[j]==-1) continue;
                if((a[i]+1)%cnt==a[j]||(a[j]+1)%cnt==a[i]||(b[i]+1)%cnt==b[j]||(b[j]+1)%cnt==b[i]){
                    fnd=true;
                    fna=i,fnb=j;
                    break;
                }
            }
            if(fnd) break;
        }
        if(fna==-1) break;
        // else if(fnb==-1) cout<<"SELFLOOP ["<<a[fna]<<" "<<b[fna]<<"] "<<fna<<endl;
        // else cout<<"PASSING ["<<a[fna]<<" "<<b[fna]<<"] ["<<a[fnb]<<" "<<b[fnb]<<"] "<<fna<<" "<<fnb<<endl;
        se.clear(),cov.clear(),cnt=0;
        a[fna]=b[fna]=-1,lasp--;
        if(fnb!=-1) a[fnb]=b[fnb]=-1,lasp--;
        for(int i=1;i<=p;i++){
            if(i==fna||i==fnb||a[i]==-1||b[i]==-1) continue;
            se.insert(a[i]),se.insert(b[i]);
        }
        for(auto it:se) cov[it]=cnt++;
        for(int i=1;i<=p;i++){
            if(a[i]==-1||b[i]==-1) continue;
            a[i]=cov[a[i]],b[i]=cov[b[i]];
        }
    }
    cout<<"Case #"<<caseno<<": ";
    if(lasp==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) maintain(t);
    return 0;
}