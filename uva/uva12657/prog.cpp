#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int lef[N+10],righ[N+10],n;
void link(int L,int R){
    righ[L]=R,lef[R]=L;
}
int main(){
    int m,kase=0;
    while(cin>>n>>m){
        for(int i=1;i<=n;++i) lef[i]=i-1,righ[i]=(i+1)%(n+1);
        righ[0]=1,lef[0]=n;
        int op,X,Y;
        bool inv=0;
        while(m--){
            cin>>op;
            if(op==4) inv=!inv;
            else{
                cin>>X>>Y;
                if(op==3&&righ[Y]==X) swap(X,Y);
                if(op!=3&&inv) op=3-op;
                if(op==1&&X==lef[Y]) continue;
                if(op==2&&X==righ[Y]) continue;

                int LX=lef[X],RX=righ[X],LY=lef[Y],RY=righ[Y];
                if(op==1) link(LX,RX),link(LY,X),link(X,Y);
                else if(op==2) link(LX,RX),link(Y,X),link(X,RY);
                else if(op==3){
                    if(righ[X]==Y) link(LX,Y),link(Y,X),link(X,RY);
                    else link(LX,Y),link(Y,RX),link(LY,X),link(X,RY);
                }
            }
        }
        int b=0;
        long long ans=0;
        for(int i=1;i<=n;++i){
            b=righ[b];
            if(i%2==1) ans+=b;
        }
        if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
        cout<<"Case "<<(++kase)<<": "<<ans<<endl;
    }
    return 0;
}