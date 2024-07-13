#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
string s;
vector<int> gr[10];
int n,ans,seq[10],ansq[10],vis[10];
void dfs(int cur,int mb){
    if(mb>ans) return;
    if(cur==n+1){
        if(ans<=mb) return;
        ans=mb;
        for(int i=1;i<=n;++i) ansq[i]=seq[i];
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        vis[i]=cur;
        seq[cur]=i;
        int u=i,nmb=mb;
        for(int v:gr[u]){
            if(vis[v]) nmb=max(nmb,vis[u]-vis[v]);
        }
        dfs(cur+1,nmb);
        vis[i]=0;
    }
}
int main(){
    while(cin>>s&&s!="#"){
        s+=";";
        int sln=s.length();
        n=0,ans=inf;
        memset(seq,0,sizeof seq);
        for(int i=1;i<=8;++i) gr[i].clear();
        map<char,int> con;
        map<int,char> reo;
        set<char> Sc;
        for(int i=0;i<sln;++i) if('A'<=s[i]&&s[i]<='Z') Sc.insert(s[i]);
        for(char c:Sc) con[c]=++n,reo[n]=c;

        for(int i=0;i<sln;++i){
            for(int j=i+2;;++j){
                if(s[j]==';'){
                    i=j;
                    break;
                }else{
                    if(!con.count(s[i])) con[s[i]]=++n,reo[n]=s[i];
                    if(!con.count(s[j])) con[s[j]]=++n,reo[n]=s[j];
                    gr[con[s[i]]].push_back(con[s[j]]);
                    gr[con[s[j]]].push_back(con[s[i]]);
                }
            }
        }
        dfs(1,0);
        for(int i=1;i<=n;++i) cout<<reo[ansq[i]]<<" ";
        cout<<"-> "<<ans<<endl;
    }
    return 0;
}