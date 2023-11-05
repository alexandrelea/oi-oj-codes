#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string a,b;
        bool ok=true;
        cin>>n>>m>>a>>b;
        a=" "+a,b=" "+b;
        char ch=b[1];
        for(int i=2;i<=m;i++){
            if(a[i+n-m]!=b[i]){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
            continue;
        }
        ok=false;
        for(int i=1;i<=n-m+1;i++) if(a[i]==ch){
            ok=true;
            break;
        }
        if(!ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}