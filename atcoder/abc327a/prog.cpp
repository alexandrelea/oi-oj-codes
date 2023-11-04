#include <iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.length()-1;i++) if((s[i]=='a'&&s[i+1]=='b')||(s[i]=='b'&&s[i+1]=='a')) return cout<<"Yes"<<endl,0;
    cout<<"No"<<endl;
    return 0;
}