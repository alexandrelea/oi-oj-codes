#include <bits/stdc++.h>
using namespace std;
const int N=3e7;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int tabl[N+5],ans[N+5];
void pregen(){
    for(int c=1;c<=N;++c){
        for(int a=c*2;a<=N;a+=c){
            int b=a-c;
            if((a^b)==c) ++tabl[a];
        }
    }
    for(int i=1;i<=N;++i) ans[i]=ans[i-1]+tabl[i];
}
int main(){
    int _,__=0,n;
    cin>>_;
    pregen();
    while(_--) cin>>n,cout<<"Case "<<(++__)<<": "<<ans[n]<<endl;
    return 0;
}