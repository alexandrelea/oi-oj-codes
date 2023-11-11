#include <iostream>
using namespace std;
int main(){
    int n,da[100],cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>da[i];
    for(int i=1;i<=n;i++){
        int mask=0,m=i;
        while(m!=0) mask|=(1<<(m%10)),m/=10;
        for(int j=1;j<=da[i];++j){
            int d=j,nmask=mask;
            while(d!=0) nmask|=(1<<(d%10)),d/=10;
            if((nmask&(nmask-1))==0) ++cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}