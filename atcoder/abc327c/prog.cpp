#include <iostream>
#define int long long
using namespace std;
int gg(int i,int j){
    i--,j--;
    return (i/3*3)+(j/3)+1;
}
signed main(){
    int rw[10]={},cw[10]={},gn[10]={};
    bool ok=true;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int v;
            cin>>v;
            rw[i]|=(1<<v-1);
            cw[j]|=(1<<v-1);
            gn[gg(i,j)]|=(1<<v-1);
        }
    }
    for(int i=1;i<=9;i++){
        if(rw[i]!=0x1ff||cw[i]!=0x1ff||gn[i]!=0x1ff) ok=false;
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}