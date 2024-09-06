// UVa 10886 - Standard Deviation
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
unsigned long long seed;
long double gen(){
    static const long double Z=(long double)1.0/(1LL<<32);
    seed>>=16,seed&=(1ULL<<32)-1,seed*=seed;
    return seed*Z;
}
long double solve(){
    int n;
    cin>>n>>seed;
    long double Ex2=0,Ex=0,nf=n;
    while(n--){
        long double x=gen();
        Ex2+=x*x,Ex+=x;
    }
    Ex2/=nf,Ex/=nf;
    return Ex2-Ex*Ex;
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--) cout<<"Case #"<<++__<<": "<<fixed<<setprecision(5)<<sqrtl(solve())<<endl;
    return 0;
}