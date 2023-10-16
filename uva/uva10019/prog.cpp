#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,nn=0,de=1;
        cin>>n;
        cout<<__builtin_popcount(n)<<" ";
        for(int i=1;i<=10;i++) nn+=de*(n%10),n/=10,de*=16;
        cout<<__builtin_popcount(nn)<<endl;
    }
    return 0;
}