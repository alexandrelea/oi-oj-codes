#include <bits/stdc++.h>
using namespace std;
int herk(int hk){
    if(hk==1) return 0;
    else return 1+herk((hk-hk%2)/2+hk%2);
}
int main(){
    string s;
    while(getline(cin,s)){
        int ml=0,cl=0,sl=s.length();
        for(int i=0;i<sl;++i){
            if(s[i]==' ') ++cl;
            else ml=max(ml,cl),cl=0;
        }
        ml=max(ml,cl);
        cout<<herk(ml)<<endl;
    }
    return 0;
}