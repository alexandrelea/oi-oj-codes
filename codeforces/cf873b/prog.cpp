#include <iostream>
using namespace std;
const int SIZE=1e5+10;
int main(){
    string st;
    int n,bal[SIZE]={},buc[3*SIZE]={},ans=0;
    cin>>n>>st;
    st=" "+st;
    for(int i=1;i<=n;i++){
        if(st[i]=='1') bal[i]=bal[i-1]+1;
        else bal[i]=bal[i-1]-1;
        if(bal[i]!=0&&buc[bal[i]+n]==0) buc[bal[i]+n]=i;
        else ans=max(ans,i-buc[bal[i]+n]);
    }
    cout<<ans<<endl;
    return 0;
}