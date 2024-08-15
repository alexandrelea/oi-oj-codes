// LG4008 - [NOI2003] 文本编辑器
// Code by Alexanderia Lea
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
crope ed;
int main(){
    ios::sync_with_stdio(false);
    int _,cur;
    cin>>_;
    while(_--){
        string op;
        cin>>op;
        if(op=="Move") cin>>cur;
        else if(op=="Insert"){
            int n,c=cur;
            char ch;
            cin>>n;
            while(n){
                ch=cin.get();
                if(32<=(int)ch&&(int)ch<=126){
                    ed.insert(c,ch);
                    ++c,--n;
                }
            }
        }else if(op=="Delete"){
            int n;
            cin>>n;
            ed.erase(cur,n);
        }else if(op=="Get"){
            int n;
            cin>>n;
            cout<<ed.substr(cur,n)<<endl;
        }else if(op=="Prev") --cur;
        else if(op=="Next") ++cur;
    }
    return 0;
}