// ABC368B - Decrease 2 max elements
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a[105];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int _=1;;++_){
        sort(a+1,a+n+1,greater<int>());
        if(a[1]>0&&a[2]>0) --a[1],--a[2];
        else{
            cout<<_-1<<endl;
            break;
        }
    }
    return 0;
}