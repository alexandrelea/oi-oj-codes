#include <bits/stdc++.h>
using namespace std;
int main(){
    int p[2][2][3],h=0,cnt[30][30][30];
    set<int> cntb;
    map<int,int> conv;
    for(int k=0;k<2;++k) for(int i=0;i<2;++i) for(int j=0;j<3;++j) cin>>p[k][i][j],cntb.insert(p[k][i][j]);
    for(int ie:cntb) conv[ie]=++h;
    for(int k=0;k<2;++k) for(int i=0;i<2;++i) for(int j=0;j<3;++j) p[k][i][j]=conv[p[k][i][j]];
    for(int k=0;k<2;++k){
        for(int x=p[k][0][0];x<p[k][1][0];++x)
            for(int y=p[k][0][1];y<p[k][1][1];++y)
                for(int z=p[k][0][2];z<p[k][1][2];++z){
                    cnt[x][y][z]++;
                    if(cnt[x][y][z]==2) return cout<<"Yes"<<endl,0;
                }
    }
    cout<<"No"<<endl;
    return 0;
}