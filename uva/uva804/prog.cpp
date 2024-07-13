#include <bits/stdc++.h>
using namespace std;
int np,nt,nf,tok[110],tko[110];
vector<int> intr[110],outr[110];
int main(){
    int _=0;
    while(cin>>np&&np){
        for(int i=1;i<=np;++i) cin>>tok[i];
        cin>>nt;
        for(int i=1;i<=nt;++i){
            intr[i].clear();
            outr[i].clear();
            int k;
            while(cin>>k&&k){
                if(k<0) intr[i].push_back(-k);
                else outr[i].push_back(k);
            }
        }
        bool dead=false;
        cin>>nf;
        cout<<"Case "<<(++_)<<": ";
        int knf;
        for(knf=1;knf<=nf;++knf){
            bool tri=false;
            for(int i=1;i<=nt;++i){
                bool ok=true;
                for(int i=1;i<=np;++i) tko[i]=tok[i];
                for(int ie:intr[i]){
                    tko[ie]--;
                    if(tko[ie]<0){
                        ok=false;
                        break;
                    }
                }
                if(!ok) continue;
                tri=true;
                for(int ie:intr[i]) tok[ie]--;
                for(int ie:outr[i]) tok[ie]++;
                break;
            }
            if(!tri){
                dead=true;
                break;
            }
        }
        if(dead) cout<<"dead after "<<knf-1<<" transitions"<<endl;
        else cout<<"still live after "<<nf<<" transitions"<<endl;
        cout<<"Places with tokens:";
        for(int i=1;i<=np;++i) if(tok[i]!=0) cout<<" "<<i<<" ("<<tok[i]<<")";
        cout<<endl<<endl;
    }
    return 0;
}