#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int size=200010;
string st;
int matc[size];
string decod(int s,int e){
    //cout<<"Do "<<s<<"~"<<e<<"."<<endl;
    int num=st[s+1]-'0',stt=0;
    if(st[s+2]>='0'&&st[s+2]<='9') num*=10,num+=st[s+2]-'0',stt=s+3;
    else stt=s+2;
    string ret="",rett="";
    for(int i=stt;i<=e-1;i++){
        if(st[i]!='[') ret.append(1,st[i]);
        else ret+=decod(i,matc[i]),i=matc[i];
    }
    for(int i=1;i<=num;i++) rett+=ret; 
    //cout<<"Done "<<s<<"~"<<e<<"."<<endl;
    return rett;
}
int main(){
    ios::sync_with_stdio(false);
    stack<int> stck;
    cin>>st;
    st="[1"+st+"]";
    for(int i=0;i<st.length();i++){
        if(st[i]=='[') stck.push(i);
        else if(st[i]==']') matc[stck.top()]=i,stck.pop();
    }
    cout<<decod(0,st.length()-1)<<endl;
    return 0;
}