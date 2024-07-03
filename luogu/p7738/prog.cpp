#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=4e5;
int n,m,l[N+1][16];
ull a1,a2;
int popc[65536];
bool s[N+1][256];
vector<int> tabl[16][65536];
ull myRand(ull &k1, ull &k2){
    ull k3=k1,k4=k2;
    k1=k4,k3^=(k3<<23),k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
void gen(int n,ull a1,ull a2){
    for(int i=1;i<=n;i++) for(int j=0;j<256;j++) s[i][j]=(myRand(a1,a2)&(1ull<<32))?1:0;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>a1>>a2,gen(n,a1,a2);
    for(int i=0;i<65536;++i) popc[i]=__builtin_popcount(i);
    for(int d=1;d<=n;++d) for(int i=0;i<16;++i){
        for(int j=0;j<16;++j) l[d][i]=l[d][i]*2+s[d][i*16+j];
        tabl[i][l[d][i]].push_back(d);
    }
    bool flg=false;
    while(m--){
        string st;
        int h[64]={},q[16]={},k;
        cin>>st>>k;
        for(int i=0;i<64;++i) h[i]=st[i]-'0',h[i]=(h[i]>=10?h[i]-7:h[i]),h[i]=(flg?15-h[i]:h[i]);
        for(int i=0;i<16;++i) for(int j=0;j<4;++j) q[i]=q[i]*16+h[i*4+j];
        flg=false;
        for(int i=0;i<16;++i){
            for(int je:tabl[i][q[i]]){
                int qdif=0;
                for(int h=0;h<16;++h){
                    qdif+=popc[l[je][h]^q[h]];
                    if(qdif>k) break;
                }
                if(qdif<=k){
                    flg=true;
                    break;
                }
            }
            if(flg) break;
        }
        cout<<flg<<endl;
    }
    return 0;
}