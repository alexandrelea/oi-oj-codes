#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int ln,w;
string o;
char op[N],var[N];
int th[N],vtth[N],stck[N],top;
int wer[N];
bool chkerr(){
    bool q=true;
    for(int i=1;i<=ln;++i){
        if(op[i]=='F'){
            if(vtth[var[i]-'a']!=0){
                cerr<<i<<endl;
                q=false;
                break;
            }
            vtth[var[i]-'a']=i;
            stck[++top]=var[i];
        }else{
            if(top==0){
                cerr<<i<<endl;
                q=false;
                break;
            }
            wer[vtth[stck[top]-'a']]=i;
            wer[i]=vtth[stck[top]-'a'];
            vtth[stck[top]-'a']=0;
            --top;
        }
    }
    if(top!=0) q=false,cerr<<"top"<<endl;
    memset(vtth,0,sizeof(vtth)),top=0;
    return q;
}
int simu(int s){
    int ans=0;
    for(int i=s+1;i<wer[s];++i){
        if(op[i]=='F'){
            if(th[i]==-1){
                i=wer[i];
                continue;
            }else if(wer[i]==i+1) ans=max(ans,th[i]);
            else ans=max(ans,simu(i));
        }
    }
    return ans+th[s];
}
void solve(){
    cin>>ln>>o;
    w=0;
    if(o.length()==4) w=0;
    else for(int i=4;o[i]!=')';++i) w=w*10+o[i]-'0';
    memset(th,0,sizeof(th));
    memset(wer,0,sizeof(wer));
    for(int i=1;i<=ln;++i){
        char o,v;
        string f,t;
        cin>>o;
        if(o=='F') cin>>v>>f>>t;
        op[i]=o,var[i]=v;
        if(f!="n"&&t!="n"){
            int fi=atoi(f.c_str()),ti=atoi(t.c_str());
            if(fi<=ti) th[i]=0;
            else th[i]=-1;
        }else if(f!="n"&&t=="n") th[i]=1;
        else if(f=="n"&&t!="n") th[i]=-1;
        else th[i]=0;
    }
    wer[0]=ln+1,th[0]=0;
    if(!chkerr()) cout<<"ERR"<<endl;
    else{
        int r=simu(0);
        if(r==w) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}