// UVa 1343 - The Rotation Game
// code by Littlelu (Lea Alexanderia).
/*
    01  02    
    03  04
05060708091011
    12  13
14151617181920
    21  22
    23  24
 */
#include <bits/stdc++.h>
using namespace std;
int tr[8][7]={{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},
                {10,9,8,7,6,5,4},{19,18,17,16,15,14,13},
                {23,21,17,12,8,3,1},{22,20,15,11,6,2,0},
                {13,14,15,16,17,18,19},{4,5,6,7,8,9,10}};
int finl[8]={6,7,8,11,12,15,16,17};
int rev[8]={5,4,7,6,1,0,3,2};
int stat[24],lim,ans[1010],lea;
inline void trans(int op){
    int tom=stat[tr[op][0]];
    for(int i=0;i<6;++i) stat[tr[op][i]]=stat[tr[op][i+1]];
    stat[tr[op][6]]=tom;
}
inline bool fin(){
    for(int i=1;i<8;++i) if(stat[finl[i]]!=stat[finl[0]]) return 0;
    return 1;
}
inline int diff(int nu){
    int tot=0;
    for(int i=0;i<8;++i) tot+=(stat[finl[i]]!=nu);
    return tot;
}
bool dfs(int dep){
    if(fin()) return lea=dep,1;
    int esti=min(diff(1),min(diff(2),diff(3)));
    if(dep+esti>lim) return 0;
    for(int i=0;i<8;++i){
        trans(i),ans[dep]=i;
        if(dfs(dep+1)) return 1;
        trans(rev[i]);
    }
    return 0;
}
int main(){
    while(cin>>stat[0]&&stat[0]){
        for(int i=1;i<24;++i) cin>>stat[i];
        for(lim=1;;++lim) if(dfs(0)) break;
        if(lea==0) cout<<"No moves needed";
        else for(int i=0;i<lea;++i) cout<<(char)(ans[i]+'A');
        cout<<endl<<stat[finl[0]]<<endl;
    }
    return 0;
}