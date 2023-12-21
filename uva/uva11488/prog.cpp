#include <iostream>
#include <cstring>
using namespace std;
const int size=3e2+10;
int soh[size*size][2]={},cts=1,ctb[size*size]={};
int main(){
    int _;
    cin>>_;
    while(_--){
        memset(soh,0,sizeof(soh)),memset(ctb,0,sizeof(ctb)),cts=1;
        int n,ans=0;
        cin>>n;
        for(int i=1,res=0;i<=n;i++,res=0){
            char str[size]={};
            cin>>str;
            for(int i=0,k=1,d=0;i<=strlen(str);i++,d++){
                if(soh[k][str[i]-'0']==0) soh[k][str[i]-'0']=++cts;
                ctb[k]++,ans=max(ans,d*ctb[k]),k=soh[k][str[i]-'0'];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}