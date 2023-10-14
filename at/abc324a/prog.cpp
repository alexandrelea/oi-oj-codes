#include <iostream>
using namespace std;
int main(){
    int n,a1,ax;
    bool neq=false;
    cin>>n>>a1;
    for(int i=1;i<n;i++){
        cin>>ax;
        if(ax!=a1){
            neq=true;
            break;
        }
    }
    if(neq) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}