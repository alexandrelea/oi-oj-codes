#include <bits/stdc++.h>
using namespace std;
int solve(int n){
    if(n==1) return 3;
    if(n==2) return 5;
    if(n==3) return 7;
    if((n-1)%3==0) return ((n-1)/3+1)*4;
	if((n-1)%3==1) return ((n-1)/3+1)*4+1;
	return ((n-1)/3+1)*4+3;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}