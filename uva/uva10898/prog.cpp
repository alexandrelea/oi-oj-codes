#include<bits/stdc++.h>
// #pragma GCC optimize(3,"Ofast")
using namespace std;
const int S=1e6+10;
int n,m,t,pw[10];
struct dish{
    int num,price;
    dish(int num=0,int price=0):num(num),price(price){}
}di[20];
int dp[S]={};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    pw[0]=1;
    for(int i=1;i<=8;i++) pw[i]=pw[i-1]*10;
    while(cin>>n){
        memset(dp,0x3f,sizeof(dp));
        int maxs=0;
        for(int i=1;i<=n;i++) cin>>di[i].price,di[i].num=pw[i-1],maxs+=pw[i-1]*9;
        cin>>m;
        for(int i=1;i<=m;i++){
            int v;
            di[n+i].price=di[n+i].num=0;
            for(int j=1;j<=n;j++){
                cin>>v;
                di[n+i].num+=v*pw[j-1];
                cerr<<v<<endl;
            }
            cin>>di[n+i].price;
        }
        for(int i=1;i<=n+m;i++) cerr<<setfill('0')<<setw(n)<<di[i].num<<" ",cerr<<di[i].price<<endl;
        dp[0]=0;
        for(int s=0;s<=maxs;++s){
            for(int i=1;i<=n+m;i++){
                bool ok=true;
                for(int j=1;j<=n;j++){
                    if(((s/pw[j-1])%10)+((di[i].num/pw[j-1])%10)>9){
                        ok=false;
                        break;
                    }
                }
                if(ok) dp[s+di[i].num]=min(dp[s+di[i].num],dp[s]+di[i].price);
            }
        }
        cin>>t;
        while(t--){
            int ss=0,v;
            for(int i=1;i<=n;i++) cin>>v,ss+=v*pw[i-1];
            cout<<dp[ss]<<endl;
        }
        cerr<<endl;
    }
    return 0;
}