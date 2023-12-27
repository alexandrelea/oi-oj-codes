#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
    if(x==2) return 1;
    if(x<=1) return 0;
    for(int i=2;i*i<=x;++i) if(x%i==0) return 0;
    return 1;
}
int main(){
    int l,cnt=0,got=0;
    cin>>l;
    for(int i=2;;++i){
        if(isprime(i)){
            if(got+i<=l) got+=i,++cnt,cout<<i<<endl;
            else break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}