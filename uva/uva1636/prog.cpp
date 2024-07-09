#include <bits/stdc++.h>
using namespace std;
int main(){
    string ss;
    while(cin>>ss){
        int a=0,b=0,n=ss.length();
        for(int i=0;i<n;++i){
            if(ss[i]=='0'&&ss[(i+1)%n]=='0') ++a;
            if(ss[i]=='0') ++b;
        }
        int h=a*n,k=b*b;
        if(h>k) cout<<"SHOOT"<<endl;
        else if(h<k) cout<<"ROTATE"<<endl;
        else cout<<"EQUAL"<<endl;
    }
    return 0;
}
