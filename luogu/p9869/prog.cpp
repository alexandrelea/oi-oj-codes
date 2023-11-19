// #include<bits/stdc++.h>
// using namespace std;
// ifstream cin("tribool.in");
// ofstream cout("tribool.out");
// const int N=1e5+10;
// int c,t,n,m,ans,cyc=false;
// int rsu[2*N],isu[2*N],vis[2*N];
// int concv(char ch){
//     if(ch=='U') return 2*n+1;
//     else if(ch=='T') return 2*n+2;
//     else return 2*n+3;
// }
// int nott(int nu){
//     if(nu<=2*n){
//         if(nu>n) return nu-n;
//         else return nu+n;
//     }else{
//         if(nu==2*n+1) return 2*n+1;
//         else if(nu==2*n+2) return 2*n+3;
//         else return 2*n+2;
//     }
// }
// string rec(int nu){
//     if(nu<=n) return to_string(nu);
//     else if(nu<=2*n) return "!"+to_string(nu-n);
//     else if(nu==2*n+1) return "U";
//     else if(nu==2*n+2) return "T";
//     else return "F";
// }
// bool hvc(int u){
//     if(u==rsu[u]) return false;
//     if(vis[u]) return vis[u]=false,true;
//     vis[u]=true;
//     bool ret=hvc(rsu[u]);
//     return vis[u]=false,ret;
// }
// bool tjc(int u){
//     if(vis[u]) return vis[u]=false,false;
//     vis[u]=true;
//     bool ret=(rsu[u]>2*n?rsu[u]==concv('U'):tjc(rsu[u]-n<0?rsu[u]:rsu[u]-n)^(rsu[u]>n));
//     return vis[u]=false,ret;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     cin>>c>>t;
//     while(t--){
//         cin>>n>>m;
//         for(int i=1;i<=2*n+3;++i) rsu[i]=i,isu[i]=0;
//         ans=0;
//         for(int i=1;i<=m;++i){
//             char ch;
//             int u,v;
//             cin>>ch;
//             if(ch=='U'||ch=='T'||ch=='F'){
//                 cin>>u;
//                 int ty=concv(ch),noty=nott(ty);
//                 rsu[u]=ty;
//                 rsu[u+n]=noty;
//             }else{
//                 cin>>u>>v;
//                 if(ch=='+') rsu[u]=rsu[v],rsu[nott(u)]=rsu[nott(v)];
//                 else rsu[u]=rsu[nott(v)],rsu[nott(u)]=rsu[v];
//             }
//         }
//         for(int i=1;i<=n*2;++i) cout<<setw(4)<<rec(i)<<" ";
//         cout<<endl;
//         for(int i=1;i<=n*2;++i) cout<<setw(4)<<rec(rsu[i])<<" ";
//         cout<<endl;
//         for(int i=1;i<=n*2;++i) cout<<setw(4)<<hvc(i)<<" ";
//         cout<<endl<<endl;
//         for(int i=1;i<=n;++i){
//             if(hvc(i)&&tjc(i)) ++ans;
//         }
//         // for(int i=1;i<=n;++i){
//         //     if(rsu[i]==concv('U')||rsu[nott(i)]==concv('U')) ++ans;
//         // }
//         cout<<ans<<endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans=0x3f3f3f3f;
char op[N];
int u[N],v[N],stt[N],edd[N];
void dfs(int s){
    if(s==n){
        int us=0;
        for(int i=1;i<=n;++i) edd[i]=stt[i],us+=(stt[i]==0);
        for(int i=1;i<=m;++i){
            if(op[i]=='U'||op[i]=='T'||op[i]=='F'){
                edd[u[i]]=(op[i]=='U'?0:op[i]=='T'?1:-1);
            }else{
                if(op[i]=='+') edd[u[i]]=edd[v[i]];
                else edd[u[i]]=-edd[v[i]];
            }
        }
        for(int i=1;i<=n;++i){
            if(edd[i]!=stt[i]) return;
        }
        ans=min(ans,us);
        return;
    }
    for(int x=-1;x<=1;++x){
        stt[s+1]=x;
        dfs(s+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;++i){
            char ch;
            int uu,vv;
            cin>>ch;
            if(ch=='U'||ch=='T'||ch=='F'){
                cin>>uu;
                op[i]=ch;
                u[i]=uu;
            }else{
                cin>>uu>>vv;
                op[i]=ch,u[i]=uu,v[i]=vv;
            }
        }
        dfs(0);
        cout<<ans<<endl;
        ans=0x3f3f3f3f;
    }
    return 0;
}