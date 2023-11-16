#include <bits/stdc++.h>
#define int __int128_t
using namespace std;
const int N=1e5+10;
int n,m,in[N];
vector<int> edge[N];
queue<int> que;
int read(){
    int x=0,s=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') s=(ch=='-'?-1:s),ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*s;
}
void print(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
struct frac{
    int num,den;
    frac(int num=0,int den=1):num(num),den(den){
        int g=gcd(this->num,this->den);
        this->num/=g,this->den/=g;
    }
    frac operator+(const frac &rhs)const{
        return frac(num*rhs.den+rhs.num*den,den*rhs.den);
    }
    frac operator/(const int &rhs)const{
        return frac(num,den*rhs);
    }
}watr[N];
signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i){
        int d=read(),v;
        while(d--){
            v=read();
            edge[i].push_back(v);
            in[v]++;
        }
    }
    for(int i=1;i<=m;++i){
        watr[i]=frac(1,1);
        que.push(i);
    }
    while(!que.empty()){
        int u=que.front();que.pop();
        frac puh=watr[u]/edge[u].size();
        for(int v:edge[u]){
            watr[v]=watr[v]+puh;
            in[v]--;
            if(in[v]==0) que.push(v);
        }
    }
    for(int i=1;i<=n;++i) if(edge[i].size()==0) print(watr[i].num),putchar(' '),print(watr[i].den),putchar('\n');
    return 0;
}