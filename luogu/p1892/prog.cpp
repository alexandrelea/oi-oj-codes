#include <bits/stdc++.h>
using namespace std;
int n,m,fa[2010],ans;
int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=2*n;++i) fa[i]=i;
    while(m--){
        char o;
        int p,q;
        cin>>o>>p>>q;
        if(o=='F') fa[find(p)]=find(q);
        else fa[find(q+n)]=find(p),fa[find(p+n)]=find(q);
    }
    for(int i=1;i<=n;++i) if(fa[i]==i) ++ans;
    cout<<ans<<endl;
    return 0;
}