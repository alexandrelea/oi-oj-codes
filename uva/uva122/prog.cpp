#include <bits/stdc++.h>
using namespace std;
string ss;
int ch[310][2],tot,val[310];
bool clet[310];
bool insert(string s){
    int nu=0,cop=0,u=0;
    for(int i=1;s[i]!=',';++i,cop=i) nu=nu*10+s[i]-'0';
    for(int i=cop+1;s[i]!=')';++i){
        int d=(s[i]=='R');
        if(ch[u][d]==-1) ch[u][d]=++tot;
        u=ch[u][d];
    }
    if(!clet[u]) clet[u]=true,val[u]=nu;
    else return false;
    return true;
}
int main(){
    bool _=false;
    while(cin>>ss){
        memset(ch,0xff,sizeof ch),tot=0;
        memset(clet,0,sizeof clet);
        bool ok=true;
        ok&=insert(ss);
        while(cin>>ss&&ss!="()") ok&=insert(ss);
        for(int i=0;i<=tot;++i) if(!clet[i]){
            ok=false;
            break;
        }
        if(!ok) cout<<"not complete";
        else{
            queue<int> que;
            que.push(0);
            bool __=false;
            while(!que.empty()){
                int u=que.front();que.pop();
                if(__) cout<<" ";
                cout<<val[u];
                if(ch[u][0]!=-1) que.push(ch[u][0]);
                if(ch[u][1]!=-1) que.push(ch[u][1]);
                __=true;
            }
        }
        cout<<endl;
    }
    return 0;
}