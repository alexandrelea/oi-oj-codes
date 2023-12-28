#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum=0,t,sqs=0;
        cin>>n;
        while(n--) cin>>t,sum+=t;
        sqs=floor(sqrt(sum));
        if(sqs*sqs==sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}