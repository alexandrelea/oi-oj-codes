#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=10001,N=M-1;
int T,x[N+10],yx[N+10];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void exgcd(int a,int b,int &x,int &y){
	if(b==0) x=1,y=0;
	else{
		exgcd(b,a%b,y,x);
		y-=x*(a/b);
	}
}
void solve(){
	cin>>T;
	for(int i=1;i<=2*T-1;i+=2) cin>>x[i];
	for(int a=0;a<M;++a){
		int c=(a+1)%M,d=(x[3]-a*a*x[1]+M)%M,g=gcd(c,M);
		if(d%g!=0) continue;
		int b,k,l=d/g;
		exgcd(c,M,b,k);
		b%=M,b*=l,b%=M;
		yx[1]=x[1];
		bool judge=true;
		for(int i=2;i<=2*T;++i){
			yx[i]=(a*yx[i-1]+b)%M;
			if(yx[i]!=x[i]&&i%2==1){
				judge=false;
				break;
			}
		}
		if(judge){
			for(int i=2;i<=2*T;i+=2) cout<<yx[i]<<endl;
			break;
		}
	}
}
signed main(){
	solve();
	return 0;
}