#include <bits/stdc++.h>
using namespace std;
int n,t[6],Q,prec[1010][30][3],pln[1010],var[30];
void getprec(){
    for(int i=1;i<=n;++i){
        for(int j=1;;++j){
            string s;
            char et;
            int nu;
            cin>>s;
            if(s.length()==1){
                cin>>et>>nu;
                prec[i][j][0]=1;
                prec[i][j][1]=s[0]-'a'+1;
                prec[i][j][2]=nu;
            }else if(s=="print"){
                cin>>et;
                prec[i][j][0]=2;
                prec[i][j][1]=et-'a'+1;
            }else if(s=="lock") prec[i][j][0]=3;
            else if(s=="unlock") prec[i][j][0]=4;
            else{
                pln[i]=j;
                prec[i][j][0]=5;
                break;
            }
        }
    }
    return;
}
void simu(){
    deque<pair<int,int>> wait,dete;
    for(int i=1;i<=n;++i) wait.push_back(make_pair(i,1));
    bool locked=0;
    while(!wait.empty()){
        int i=wait.front().first,j=wait.front().second;wait.pop_front();
        // cerr<<i<<" "<<j<<" %"<<endl;
        int lesQ=Q;
        bool ok=1;
        for(;lesQ>0&&j<=pln[i];lesQ-=t[prec[i][j][0]],++j){
            // cerr<<"# "<<i<<" $"<<j<<endl;
            if(prec[i][j][0]==1) var[prec[i][j][1]]=prec[i][j][2];
            else if(prec[i][j][0]==2) cout<<i<<": "<<var[prec[i][j][1]]<<endl;
            else if(prec[i][j][0]==3){
                if(!locked) locked=1;
                else{
                    ok=0;
                    dete.push_back(make_pair(i,j));
                    break;
                }
            }else if(prec[i][j][0]==4){
                locked=0;
                if(dete.size()>0){
                    wait.push_front(dete.front());
                    dete.pop_front();
                }
            }else if(prec[i][j][0]==5) ok=0;
        }
        if(ok) wait.push_back(make_pair(i,j));
    }
}
int main(){
    int _,__=0;
    cin>>_;
    while(_--){
        if(__) cout<<endl;
        memset(prec,0,sizeof prec);
        memset(pln,0,sizeof pln);
        memset(var,0,sizeof var);
        cin>>n;
        for(int i=1;i<=5;++i) cin>>t[i];
        cin>>Q;
        getprec();
        simu();
        __=1;
    }
    return 0;
}