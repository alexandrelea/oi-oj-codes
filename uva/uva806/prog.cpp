#include <bits/stdc++.h>
using namespace std;
int n,seq[10000],ch[10000][5],ty[10000],tot=0;
bool fig[80][80];
void build(int r0,int c0,int ln,int &u){
    if(u==0) u=++tot;
    if(ln>1){
        int sln=ln/2;
        build(r0,c0,sln,ch[u][1]);
        build(r0,c0+sln,sln,ch[u][2]);
        build(r0+sln,c0,sln,ch[u][3]);
        build(r0+sln,c0+sln,sln,ch[u][4]);
        if(ty[ch[u][1]]==ty[ch[u][2]]&&ty[ch[u][2]]==ty[ch[u][3]]&&ty[ch[u][3]]==ty[ch[u][4]]){
            if(ty[ch[u][1]]!=-1) ty[u]=ty[ch[u][1]];
            else ty[u]=-1;
        }else ty[u]=-1;
    }else{
        ty[u]=fig[r0][c0];
        return;
    }
}
void genseq(int u,vector<int> roc){
    if(ty[u]==1){
        reverse(roc.begin(),roc.end());
        int su=0;
        for(int ie:roc) su=su*5+ie;
        seq[++tot]=su;
    }else if(ty[u]==-1){
        for(int i=1;i<=4;++i){
            vector<int> nroc=roc;
            nroc.push_back(i);
            genseq(ch[u][i],nroc);
        }
    }
}
void fig2seq(){
    memset(ch,0,sizeof ch);
    memset(seq,0,sizeof seq);
    memset(ty,0,sizeof ty);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j){
        char c;
        cin>>c;
        fig[i][j]=c-'0';
    }
    int rho=0;
    tot=0;
    build(0,0,n,rho);
    tot=0;
    genseq(rho,{});
    sort(seq+1,seq+tot+1);
    for(int i=1;i<=tot;++i){
        if(i%12==1) cout<<endl<<seq[i];
        else cout<<" "<<seq[i];
    }
    cout<<endl<<"Total number of black nodes = "<<tot<<endl;
}
void cover(int r0,int c0,int ln,vector<int> pth){
    if(pth.size()==0){
        for(int i=r0;i<r0+ln;++i) for(int j=c0;j<c0+ln;++j) fig[i][j]=1;
    }else{
        int ch=pth[pth.size()-1];pth.pop_back();
        switch(ch){
            case 1:cover(r0,c0,ln/2,pth);break;
            case 2:cover(r0,c0+ln/2,ln/2,pth);break;
            case 3:cover(r0+ln/2,c0,ln/2,pth);break;
            case 4:cover(r0+ln/2,c0+ln/2,ln/2,pth);break;
        }
        return;
    }
}
void seq2fig(){
    memset(fig,0,sizeof fig);
    n=-n;
    int vr;
    while(cin>>vr&&vr!=-1) seq[++tot]=vr;
    for(int i=1;i<=tot;++i){
        vector<int> pth;
        while(seq[i]) pth.push_back(seq[i]%5),seq[i]/=5;
        reverse(pth.begin(),pth.end());
        cover(0,0,n,pth);
    }
    cout<<endl;
    for(int i=0;i<n;++i,cout<<endl) for(int j=0;j<n;++j){
        if(fig[i][j]) cout<<"*";
        else cout<<".";
    }
}
int main(){
    int _=0,__=0;
    while(cin>>n&&n!=0){
        if(__) cout<<endl;
        cout<<"Image "<<(++_);
        if(n>0) fig2seq();
        else seq2fig();
        __=1;
    }
    return 0;
}