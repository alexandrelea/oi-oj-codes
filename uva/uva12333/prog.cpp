#include <bits/stdc++.h>
using namespace std;
const int N=5e6,M=2.1e4;
int ch[N+10][10]={},nu[N+10]={},tot=1;
int a[M],b[M],c[M],d[M];
void add(){
    int l=max(a[0],b[0]);
    for(int i=1;i<=l;++i) c[i]=a[i]+b[i];
    for(int i=1;i<l;++i) c[i+1]+=c[i]/10,c[i]%=10;
    c[0]=l;
    if(c[l]>=10) c[l+1]=c[l]/10,c[l]%=10,++c[0];
}
void ins(int vu){
    int u=1,k=0;
    for(int i=0;i<=c[0];++i) d[i]=c[i];
    reverse(d+1,d+d[0]+1);
    for(int i=1;i<=d[0];++i){
        if(k>40) break;
        if(ch[u][d[i]]==-1) ch[u][d[i]]=++tot;
        u=ch[u][d[i]];
        nu[u]=(nu[u]==-1?vu:nu[u]);
        ++k;
    }
}
int main(){
    a[0]=b[0]=a[1]=b[1]=c[0]=c[1]=1;
    memset(nu,0xff,sizeof nu);
    memset(ch,0xff,sizeof ch);
    ins(0),ins(1);
    for(int i=2;i<100000;++i){
        add();
        ins(i);
        memcpy(a,b,sizeof b),memcpy(b,c,sizeof c);
    }
    int t,_=0;
    cin>>t;
    string ss;
    while(t--){
        cin>>ss;
        cout<<"Case #"<<(++_)<<": ";
        int u=1,sl=ss.length();
        bool ok=true;
        for(int i=0;i<sl;++i){
            if(ch[u][ss[i]-'0']==-1){
                ok=false;
                break;
            }
            u=ch[u][ss[i]-'0'];
        }
        if(ok) cout<<nu[u]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}