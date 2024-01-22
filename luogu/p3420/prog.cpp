#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,fa[N],ans;
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=n;++i){
        int x=i,y;
        cin>>y;
        x=find(x),y=find(y);
        fa[x]=y;
    }
    for(int i=1;i<=n;++i) if(fa[i]==i) ++ans;
    cout<<ans<<endl;
	return 0;
}