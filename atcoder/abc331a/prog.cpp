#include <bits/stdc++.h>
using namespace std;
int main(){
    int M,D,y,m,d;
    cin>>M>>D>>y>>m>>d;
    ++d;
    if(d==D+1) d=1,++m;
    if(m==M+1) m=1,++y;
    cout<<y<<" "<<m<<" "<<d<<endl;
    return 0;
}