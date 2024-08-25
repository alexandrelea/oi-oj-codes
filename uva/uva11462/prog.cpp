// UVa11462 - Age Sort
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,x,c[105];
int main(){
    while(scanf("%d",&n)==1&&n){
        memset(c,0,sizeof c);
        for(int i=1;i<=n;++i) scanf("%d",&x),++c[x];
        bool _=0;
        for(int i=1;i<=100;++i){
            for(int j=1;j<=c[i];++j){
                if(_) putchar(' ');
                _=1,printf("%d",i);
            }
        }
        puts("");
    }
    return 0;
}