#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N],ans;
int find(int x){
    return fa[x]=(x==fa[x]?fa[x]:find(fa[x]));
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n*m;++i) fa[i]=i;
    while(k--){
        int a,b;
        cin>>a>>b;
        a=find(a),b=find(b);
        fa[a]=b;
    }
    for(int i=1;i<=n*m;++i) if(fa[i]==i) ++ans;
    cout<<ans<<endl;
	return 0;
}