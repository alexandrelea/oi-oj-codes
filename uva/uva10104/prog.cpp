#include <iostream>
using namespace std;
typedef long long lnt;
lnt exgcd(lnt a,lnt b,lnt &g,lnt &x,lnt &y){
    if(b==0) return g=a,x=1,y=0,a;
    else return exgcd(b,a%b,g,y,x),y-=a/b*x,g;
}
int main(){
    lnt a,b,x,y,g;
    while(cin>>a>>b){
        exgcd(a,b,g,x,y);
        cout<<x<<" "<<y<<" "<<g<<endl;
    }
    return 0;
}