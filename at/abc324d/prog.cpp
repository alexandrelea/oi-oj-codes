#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,ans=0;
    string st;
    cin>>n>>st;
    sort(st.begin(),st.end());
    long long pw10=1;
    for(int i=1;i<=n;i++) pw10*=10;
    for(long long i=0;i*i<=pw10;i++){
        string sq=to_string(i*i);
        sq.resize(n,'0');
        sort(sq.begin(),sq.end());
        if(sq==st) ans++;
    }
    cout<<ans<<endl;
    return 0;
}