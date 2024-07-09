#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,v[10],_=0;
    string str;
    while(cin>>n&&n){
        for(int i=0;i<n;++i){
            char c;
            int u;
            cin>>c>>u;
            v[i]=u-1;
        }
        cin>>str;
        int q;
        cin>>q;
        cout<<"S-Tree #"<<(++_)<<":"<<endl;
        while(q--){
            string k;
            cin>>k;
            int l=k.length(),p=0;
            for(int i=0;i<l;++i) p=p*2+k[v[i]]-'0';
            cout<<str[p];
        }
        cout<<endl<<endl;
    }
    return 0;
}