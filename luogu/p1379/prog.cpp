#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <queue>
using namespace std;
int main(){
    string bod,want="123804765";
    queue<string> que;
    __gnu_pbds::gp_hash_table<string,int> from,stp;
    const int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};

    cin>>bod;
    
    if(bod==want) return cout<<"0"<<endl,0;
    que.push(bod),que.push(want);
    from[bod]=1,from[want]=2;
    stp[bod]=0,stp[want]=1;
    while(!que.empty()){
        string nw=que.front();que.pop();
        //cout<<nw<<","<<from[nw]<<endl;
        char tab[4][4]={{},{'\0',nw[0],nw[1],nw[2]},{'\0',nw[3],nw[4],nw[5]},{'\0',nw[6],nw[7],nw[8]}};
        int x0,y0;
        for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) if(tab[i][j]=='0'){
            x0=i;
            y0=j;
            break;
        }
        for(int d=0;d<4;d++){
            int nx=x0+dir[d][0],ny=y0+dir[d][1];
            //cout<<nx<<" "<<ny<<endl;
            if(nx<1||nx>3||ny<1||ny>3) continue;
            swap(tab[nx][ny],tab[x0][y0]);
            string aft="";
            for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) aft.append(1,tab[i][j]);
            swap(tab[nx][ny],tab[x0][y0]);
            if(from[aft]==from[nw]) continue;
            if(from[aft]+from[nw]==3){
                cout<<stp[aft]+stp[nw]<<endl;
                return 0;
            }
            from[aft]=from[nw];
            stp[aft]=stp[nw]+1;
            que.push(aft);
            //cout<<"p "<<aft<<endl;
        }
        //cout<<endl;

    }
    return 0;
}