// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N=6e5+10;
// int n,m,to[N][4],tot=1,l;
// bool etg[N];
// char s[N];
// void insert(){
//     int u=1;
//     l=strlen(s);
//     for(int i=0;i<l;++i){
//         if(to[u][s[i]-'a']==0) to[u][s[i]-'a']=++tot;
//         u=to[u][s[i]-'a'];
//     }
//     etg[u]=1;
// }
// bool dfs(int u,int i,bool tag){
//     if(i>=l) return tag&&etg[u];
//     int c=s[i]-'a';
//     if(to[u][c]!=0&&dfs(to[u][c],i+1,tag)) return true;
//     if(tag) return false;
//     for(int e=0;e<=2;++e) if(to[u][e]!=0&&dfs(to[u][e],i+1,true)&&e!=c) return true;
//     return false;
// }
// signed main(){
//     scanf("%d %d",&n,&m);
//     for(int i=1;i<=n;++i){
//         scanf("%s",s);
//         insert();
//     }
//     while(m--){
//         scanf("%s",s);
//         l=strlen(s);
//         if(dfs(1,0,false)) printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=23333333377;
set<ll> ht;
int n,m;
string tmp;
ll hashe(string x){
    int len=x.length();
    ll hshv=0;
    for(int i=0;i<len;++i) hshv=(hshv*4+1ll*(x[i]-'a'))%mod;
    return hshv;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        cin>>tmp;
        ht.insert(hashe(tmp));
    }
    for(int i=1;i<=m;++i){
        bool flag=false;
        cin>>tmp;
        ll h=hashe(tmp);
        int len=tmp.size();
        ll base=1;
        for(int j=len-1;j>=0;--j){
            if(flag) break;
            for(int k=0;k<3;++k){
                if(tmp[j]-'a'==k) continue;
                ll res=(h-(tmp[j]-'a')*base%mod+k*base%mod+mod)%mod;
                if(ht.count(res)){
                    flag=true;
                    break;
                }
            }
            base=base*4%mod;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}