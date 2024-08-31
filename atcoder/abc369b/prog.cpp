// Atcoder Beginner's Contest 369B - Piano 3
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
int n,a[105],s[105],ans=0x3f3f3f3f;
char ch;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]>>ch,s[i]=ch=='R';
    for(int i=1;i<=100;++i) for(int j=1;j<=100;++j){
        int l=i,r=j,sum=0;
        for(int i=1;i<=n;++i){
            if(s[i]) sum+=abs(a[i]-r),r=a[i];
            else sum+=abs(a[i]-l),l=a[i];
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}