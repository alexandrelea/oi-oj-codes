#include <iostream>
using namespace std;
const int size=1e7+10;
int ct,root;
int val[size],rnd[size],siz[size],ch[size][2];
int create(int v){
    siz[++ct]=1,val[ct]=v,rnd[ct]=rand();
    return ct;
}
void pushup(int cur){
    siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
}
void split(int cur,int v,int &x,int &y){
    if(cur==0) return x=y=0,void();
    if(val[cur]<=v) x=cur,split(ch[x][1],v,ch[x][1],y);
    else y=cur,split(ch[y][0],v,x,ch[y][0]);
    return pushup(cur);
}
int merge(int x,int y){
    if(x==0||y==0) return x+y;
    if(rnd[x]<rnd[y]) return ch[x][1]=merge(ch[x][1],y),pushup(x),x;
    else return ch[y][0]=merge(x,ch[y][0]),pushup(y),y;
}
void insert(int x){
    int l,r;
    split(root,x,l,r);
    root=merge(merge(l,create(x)),r);
}
void remove(int x){
    int l,r,xx,yy;
    split(root,x,l,r),split(l,x-1,xx,yy);
    yy=merge(ch[yy][0],ch[yy][1]),root=merge(merge(xx,yy),r);
}
int rnk(int x){
    int l,r,tmp;
    split(root,x-1,l,r);
    tmp=siz[l]+1,root=merge(l,r);
    return tmp;
}
int kth(int cur,int k){
    int p=siz[ch[cur][0]]+1;
    if(p==k) return val[cur];
    if(p<k) return kth(ch[cur][1],k-p);
    return kth(ch[cur][0],k);
}
int pre(int x){
    int l,r,tmp;
    split(root,x-1,l,r);
    tmp=kth(l,siz[l]),root=merge(l,r);
    return tmp;
}
int sub(int x){
    int l,r,tmp;
    split(root,x,l,r);
    tmp=kth(r,1),root=merge(l,r);
    return tmp;
}
int main(){
    int n,o,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>o>>x;
        if(o==1) insert(x);
        if(o==2) remove(x);
        if(o==3) cout<<rnk(x)<<endl;
        if(o==4) cout<<kth(root,x)<<endl;
        if(o==5) cout<<pre(x)<<endl;
        if(o==6) cout<<sub(x)<<endl;
    }
    return 0;
}