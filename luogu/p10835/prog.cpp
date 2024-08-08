#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        int n,m;
        cin>>n>>m;
        if((m%2==1&&n>=1)||(m%2==0&&n==0)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}