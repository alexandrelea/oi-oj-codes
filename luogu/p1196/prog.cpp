#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int fa[N],dis[N],siz[N],t;
int find(int x){
    if(fa[x]==x) return x;
    int fax=find(fa[x]);
    dis[x]+=dis[fa[x]];
    return fa[x]=fax;
}
int main(){
    cin>>t;
    for(int i=1;i<=3e4;++i) fa[i]=i,siz[i]=1;
    while(t--){
        char o;
        int x,y;
        cin>>o>>x>>y;
        if(o=='M'){
            x=find(x),y=find(y);
            dis[x]+=siz[y],fa[x]=y,siz[y]+=siz[x],siz[x]=0;
        }else{
            if(find(x)!=find(y)) cout<<-1<<endl;
            else cout<<abs(dis[x]-dis[y])-1<<endl;
        }
    }
    return 0;
}