#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,arr[110];
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=n/2+n%2;i<=n;++i) arr[i]=i;
        for(int i=n/2+n%2-1;i>=1;--i){
            int mu=0;
            for(int j=i;j<=n;j+=i) mu+=arr[j],mu%=i;
            arr[i]=(i-mu+i)%i+i;
        }
        for(int i=1;i<=n;++i) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}