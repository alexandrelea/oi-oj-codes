// UVa 10294 - Arif in Dhaka (First Love Part 2)
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n,t;
    while(cin>>n>>t&&n){
        ll pw[55];
        pw[0]=1;
        for(int i=1;i<=n;++i) pw[i]=pw[i-1]*t;
        ll a=0;
        for(int i=0;i<n;++i) a+=pw[gcd(i,n)];
        ll b=0;
        if(n%2==1) b=n*pw[(n+1)/2];
        else b=n/2*(pw[n/2+1]+pw[n/2]);
        cout<<a/n<<" "<<(a+b)/2/n<<endl;
    }
    return 0;
}