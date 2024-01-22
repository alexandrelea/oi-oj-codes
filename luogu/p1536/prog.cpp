#include <bits/stdc++.h>
using namespace std;
int n,m,fa[1010],ans;
int find(int x){
    return fa[x]=(fa[x]!=x?find(fa[x]):x);
}
int main(){
    while(cin>>n&&n!=0){
        cin>>m;
        ans=0;
        for(int i=1;i<=n;++i) fa[i]=i;
        while(m--){
            int a,b;
            cin>>a>>b;
            a=find(a),b=find(b);
            fa[a]=b;
        }
        for(int i=1;i<=n;++i) if(fa[i]==i) ++ans;
        cout<<ans-1<<endl;
    }
	return 0;
}