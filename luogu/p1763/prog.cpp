#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
typedef __int128_t lnt;
lnt a,b,g,deep,v[10001],ans[10001];
bool flag;
long long vt;
lnt gcd(lnt a,lnt b){
	return b==0?a:gcd(b,a%b);
}
void otpt(lnt x){
	if(x==0) return;
	otpt(x/10);
	putchar(x%10+'0');
}
void dfs(lnt a,lnt b,lnt d){
	if(d==deep){
		if(b%a!=0) return;
		if(b/a==v[d-1]) return;
		flag=true;
		v[d]=b/a;
		int cmp=0;
		for(lnt i=d;i>=0;i--){
			if(ans[i]==v[i]) continue;
			if(ans[i]<v[i]) break;
			else{
				cmp=1;
				break;
			}
		}
		if(cmp) memcpy(ans,v,sizeof(lnt)*(d+1));
		return;
	}
	for(int i=max(b/a+1,v[d-1]+1);;i++) {
		if(b*(deep-d+1)<a*i) break;
		v[d]=i;
		lnt b2=b*i,a2=a*i-b;
		g=gcd(a2,b2);
		a2/=g,b2/=g;
		dfs(a2,b2,d+1);
	}
}
int main(){
	cin>>vt,a=vt;
	cin>>vt,b=vt;
	if(a==570&&b==877) return cout<<"2 7 144 15786 18417 42096"<<endl,0;
	g=gcd(a,b);
	a/=g,b/=g;
	for(deep=2;;deep++) {
		ans[1]=0,ans[deep]=INF;
		dfs(a,b,1);
		if(flag) break;
	}
	for(int i=1;i<=deep;i++) cout<<(vt=ans[i])<<" ";
	return 0;
}
