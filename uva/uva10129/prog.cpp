#include <bits/stdc++.h>
using namespace std;
int n,fa[30],in[30],ot[30],tot;
map<int,char> mch;
int find(int u){
    return fa[u]=fa[u]==u?fa[u]:find(fa[u]);
}
void merge(int u,int v){
    u=find(u),v=find(v);
    fa[v]=u;
}
void solve(){
    cin>>n;
    for(int i=1;i<=26;++i) fa[i]=i,in[i]=0,ot[i]=0;
    mch.clear(),tot=0;
    for(int i=1;i<=n;++i){
        string st;
        cin>>st;
        int sl=st.length();
        if(!mch.count(st[0])) mch[st[0]]=++tot;
        if(!mch.count(st[sl-1])) mch[st[sl-1]]=++tot;
        int u=mch[st[0]],v=mch[st[sl-1]];
        ot[u]++,in[v]++;
        merge(u,v);
    }
    bool ok=true;
    int c=0,ce[2]={};
    for(int i=1;i<=tot;++i) c+=fa[i]==i;
    if(c!=1) ok=false;
    for(int i=1;i<=tot;++i){
        ce[abs(ot[i]-in[i])]++;
        if(abs(ot[i]-in[i])>1){
            ok=false;
            break;
        }
    }
    if(!(ce[1]==0||ce[1]==2)) ok=false;
    if(ok) cout<<"Ordering is possible."<<endl;
    else cout<<"The door cannot be opened."<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}