#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,fa[N];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) fa[i]=i;
	while(m--){
		int z,x,y;
		cin>>z>>x>>y;
		x=find(x),y=find(y);
		if(z==1) fa[x]=y;
		else cout<<(char)(x==y?'Y':'N')<<endl;
	}
	return 0;
}