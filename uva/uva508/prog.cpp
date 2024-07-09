#include <bits/stdc++.h>
using namespace std;
char ch;
string ss;
map<char,string> morse;
map<string,string> dict;
map<string,vector<string>> redict;
int main(){
    while(cin>>ch&&ch!='*') cin>>ss,morse[ch]=ss;
    while(cin>>ss&&ss!="*"){
        int sslen=ss.length();
        string moc="";
        for(int i=0;i<sslen;++i) moc+=morse[ss[i]];
        cerr<<ss<<" "<<moc<<endl;
        dict[ss]=moc,redict[moc].push_back(ss);
    }
    while(cin>>ss&&ss!="*"){
        if(redict[ss].size()==1) cout<<redict[ss][0]<<endl;
        else if(redict[ss].size()>1) cout<<redict[ss][0]<<"!"<<endl;
        else{
            int mch=0x3f3f3f3f;
            string ans;
            for(auto ie:dict){
                string h=ie.second;
                int hl=h.length(),sl=ss.length();
                if((hl<sl&&ss.substr(0,hl)==h)||(sl<hl&&h.substr(0,sl)==ss)){
                    if(abs(sl-hl)<mch) mch=abs(sl-hl),ans=ie.first;
                }
            }
            cout<<ans<<"?"<<endl;
        }
    }
    return 0;
}