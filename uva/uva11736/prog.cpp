#include <bits/stdc++.h>
using namespace std;
int b,v,q;
struct var{
    string s;
    int t;
    unsigned long long dta;
}vars[210];
char eee;
int main(){
    while(cin>>b>>v){
        for(int i=1;i<=v;++i) cin>>vars[i].s>>vars[i].t,vars[i].dta=0;
        for(int i=1;i<=v;++i){
            unsigned long long &dta=vars[i].dta;
            dta=0;
            for(int j=1;j<=vars[i].t;++j){
                for(int k=1;k<=b;++k){
                    cin>>eee;
                    dta=dta*2+(eee-'0');
                }
            }
        }
        cin>>q;
        while(q--){
            string qr;
            cin>>qr;
            cout<<qr<<"=";
            for(int i=1;i<=v;++i){
                if(vars[i].s==qr){
                    cout<<vars[i].dta;
                    break;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}