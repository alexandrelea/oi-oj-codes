#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,f[(1<<17)][30],ans=0;
    string st[20];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>st[i],f[(1<<i-1)][st[i][st[i].length()-1]-'A']=st[i].length(),ans=max(ans,(int)st[i].length());
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int S=0;S<(1<<n);S++){
        if(S&(1<<(j-1))) continue;
        else{
            f[S|(1<<(j-1))][st[j][st[j].size()-1]-'A']=max(f[S|(1<<(j-1))][st[j][st[j].size()-1]-'A'],(int)(f[S][st[j][0]-'A']+st[j].length()));
            ans=max(ans,f[S|(1<<(j-1))][st[j][st[j].size()-1]-'A']);
        }
    }
    cout<<ans<<endl;
    return 0;
}