// CF1907A - Rook
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int main(){
    int _;
    cin>>_;
    while(_--){
        string pos;
        cin>>pos;
        string px=pos,py=pos;
        px[0]='a',py[1]='1';
        for(int i=0;i<8;++i,++px[0]) if(px!=pos) cout<<px<<endl;
        for(int i=0;i<8;++i,++py[1]) if(py!=pos) cout<<py<<endl;
    }
    return 0;
}