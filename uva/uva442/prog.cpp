#include <bits/stdc++.h>
using namespace std;
struct matx{
    int a,b;
    matx(int a=0,int b=0):a(a),b(b){};
}m[30];
stack<matx> s;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string nam;
        cin>>nam;
        int k=nam[0]-'A';
        cin>>m[k].a>>m[k].b;
    }
    string expr;
    while(cin>>expr){
        int len=expr.length();
        bool err=false;
        int ans=0;
        for(int i=0;i<len;++i){
            if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if(expr[i]==')'){
                matx m2=s.top();s.pop();
                matx m1=s.top();s.pop();
                if(m1.b!=m2.a){
                    err=true;
                    break;
                }
                ans+=m1.a*m1.b*m2.b;
                s.push(matx(m1.a,m2.b));
            }
        }
        if(err) cout<<"error"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}