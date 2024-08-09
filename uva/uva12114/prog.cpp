#include <bits/stdc++.h>
using namespace std;
double f(double a,double b){
    return min((a/b),1.0);
}
int main(){
    int a,b,_=0;
    while(cin>>b>>a&&a&&b){
        cout<<"Case "<<(++_)<<": ";
        if(b==1) cout<<":-\\"<<endl;
        else if(f(a,b)==f(a-1,b-1)) cout<<":-|"<<endl;
        else if(f(a,b)>f(a-1,b-1)) cout<<":-("<<endl;
        else cout<<":-)"<<endl;
    }
    return 0;
}
