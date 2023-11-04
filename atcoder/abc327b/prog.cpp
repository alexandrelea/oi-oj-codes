#include <iostream>
#define int long long
using namespace std;
int f(int x){
    int q=1;
    for(int i=1;i<=x;i++) q*=x;
    return q;
}
signed main(){
    int x;
    cin>>x;
    for(int i=1;i<=16;i++) if(f(i)==x) return cout<<i<<endl,0;
    cout<<-1<<endl;
    return 0;
}