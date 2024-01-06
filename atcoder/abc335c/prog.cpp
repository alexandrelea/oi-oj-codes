#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct po{
    int x,y;
    po(int x=0,int y=0):x(x),y(y){}
}que[N];
int n,q,hd,tl;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;++i) que[i]=po(n-i+1,0);
    hd=1,tl=n+1;
    while(q--){
        // for(int i=hd;i<tl;++i) cerr<<que[i].x<<" "<<que[i].y<<endl;
        // cerr<<endl;
        int o;
        cin>>o;
        if(o==1){
            char d;
            cin>>d;
            if(d=='U') que[tl]=po(que[tl-1].x,que[tl-1].y+1),tl++,hd++;
            if(d=='D') que[tl]=po(que[tl-1].x,que[tl-1].y-1),tl++,hd++;
            if(d=='R') que[tl]=po(que[tl-1].x+1,que[tl-1].y),tl++,hd++;
            if(d=='L') que[tl]=po(que[tl-1].x-1,que[tl-1].y),tl++,hd++;
        }else{
            int p;
            cin>>p;
            cout<<que[tl-p].x<<" "<<que[tl-p].y<<endl;
        }
    }
    return 0;
}