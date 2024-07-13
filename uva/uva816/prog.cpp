#include <bits/stdc++.h>
using namespace std;
map<char,int> nesw={{'N',0},{'E',1},{'S',2},{'W',3}};
map<char,int> turn={{'L',0},{'F',1},{'R',2}};
const int cowk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int r0,c0,r1,c1,r_,c_,dis[15][15][4]={};
char et;
bool to[15][15][4][3];
struct qnod{
    int r,c,fc;
    qnod(int r=0,int c=0,int fc=0):r(r),c(c),fc(fc){}
}pafr[15][15][4];
qnod walk(qnod cur,int tun){
    int nfc=cur.fc;
    nfc=(nfc+tun+3)%4;
    return qnod(cur.r+cowk[nfc][0],cur.c+cowk[nfc][1],nfc);
}
void pans(qnod cur){
    vector<qnod> ans;
    while(dis[cur.r][cur.c][cur.fc]!=0x3f3f3f3f){
        ans.push_back(cur);
        cur=pafr[cur.r][cur.c][cur.fc];
    }
    ans.push_back(qnod(r0,c0));
    reverse(ans.begin(),ans.end());
    int cnt=0;
    cout<<" ";
    for(auto ie:ans){
        if(cnt%10==0&&cnt!=0) cout<<endl<<" ";
        cout<<" ("<<ie.r<<","<<ie.c<<")";
        ++cnt;
    }
    cout<<endl;
}
int main(){
    string name;
    while(cin>>name&&name!="END"){
        cout<<name<<endl;
        memset(dis,0x3f,sizeof dis);
        memset(to,0,sizeof to);
        cin>>r0>>c0>>et>>r1>>c1;
        while(cin>>r_&&r_!=0){
            cin>>c_;
            string ss;
            while(cin>>ss&&ss!="*"){
                for(int i=1;i<ss.length();++i) to[r_][c_][nesw[ss[0]]][turn[ss[i]]]=1;
            }
        }
        qnod st=walk(qnod(r0,c0,nesw[et]),1);
        queue<qnod> que;
        que.push(st),dis[st.r][st.c][st.fc]=0,pafr[st.r][st.c][st.fc]=qnod(0,0,0);
        bool ok=false;
        while(!que.empty()){
            qnod cur=que.front();que.pop();
            if(cur.r==r1&&cur.c==c1){
                ok=true;
                pans(cur);
                break;
            }
            for(int i=0;i<3;++i){
                if(!to[cur.r][cur.c][cur.fc][i]) continue;
                qnod ext=walk(cur,i);
                if(ext.r<1||ext.r>9||ext.c<0||ext.c>9) continue;
                if(dis[ext.r][ext.c][ext.fc]>dis[cur.r][cur.c][cur.fc]+1){
                    dis[ext.r][ext.c][ext.fc]=dis[cur.r][cur.c][cur.fc]+1;
                    pafr[ext.r][ext.c][ext.fc]=cur;
                    que.push(ext);
                }
            }
        }
        if(!ok) cout<<"  No Solution Possible"<<endl;
    }
    return 0;
}