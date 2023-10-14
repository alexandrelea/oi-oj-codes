#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    while(n%2==0) n/=2;
    while(n%3==0) n/=3;
    if(n!=1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}