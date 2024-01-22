#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int fa[N*3],n,k,ans;
int find(int x){
    return fa[x]=(fa[x]==x?fa[x]:find(fa[x]));
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n*3;++i) fa[i]=i;
    while(k--){
        int o,x,y;
        cin>>o>>x>>y;
        if(x>n||y>n){
            ++ans;
            continue;
        }
        if(o==1){
            if(find(x+n)==find(y)||find(x)==find(y+n)) ++ans;
            else merge(x,y),merge(x+n,y+n),merge(x+n+n,y+n+n);
        }else if(o==2){
            if(find(x)==find(y)||find(x)==find(y+n)) ++ans;
            else merge(x+n,y),merge(x+n+n,y+n),merge(x,y+n+n);
        }
    }
    cout<<ans<<endl;
    return 0;
}