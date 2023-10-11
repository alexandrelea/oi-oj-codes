#include <iostream>
#include <cstring>
using namespace std;
const int SIZE=1e6+10;
int n,p,a,b,lasp;
int las[SIZE],nex[SIZE],uord[SIZE]={},pot[SIZE]={};
void rmov(int x){
    las[nex[x]]=las[x];
    nex[las[x]]=nex[x];
    uord[x]=0;
}
void maintain(int caseno){
    cin>>n>>p,lasp=p;
    memset(uord,0,sizeof(uord));
    memset(pot,0,sizeof(pot));
    for(int i=0;i<n;i++) las[i]=i-1,nex[i]=i+1;
    las[0]=n-1,nex[n-1]=0;
    for(int i=1;i<=p;i++){
        cin>>a>>b;
        uord[a]=1,uord[b]=-1;
        pot[a]=b,pot[b]=a;
    }
    for(int i=0;i<n;i++) if(uord[i]==0) rmov(i); 
    int nw=0;
    while(lasp){
        bool fund=false;
        while(uord[nw]==0) nw=(nw+1)%n;
        for(int i=nex[nw];i!=nw&&(!fund);i=nex[i]){
            int u=i,v=nex[i];
            if(uord[u]==uord[v]&&(nex[pot[u]]==pot[v]||nex[pot[v]]==pot[u])) rmov(u),rmov(v),rmov(pot[u]),rmov(pot[v]),lasp-=2,fund=true;
            else if(pot[u]==v||pot[v]==u) rmov(u),rmov(v),lasp--,fund=true;
        }
        if(!fund) break;
    }
    cout<<"Case #"<<caseno<<": ";
    if(lasp==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) maintain(t);
    return 0;
}