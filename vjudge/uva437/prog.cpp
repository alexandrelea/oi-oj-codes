#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct cub{
    int x,y,z;
    cub(int x,int y,int z):x(x),y(y),z(z){}
};
vector<cub> cubs;
unordered_map<int,int> mono;
int dp(int x){
    if(mono.count(x)) return mono[x];
    int ans=cubs[x].z;
    for(int i=0;i<cubs.size();i++)
        if((cubs[i].x<cubs[x].x&&cubs[i].y<cubs[x].y)||(cubs[i].x<cubs[x].y&&cubs[i].y<cubs[x].x))
            ans=max(ans,cubs[x].z+dp(i));
    return mono[x]=ans;
}
int maintain(int n){
    int ans=0;
    mono.clear();
    cubs.clear();
    for(int i=1;i<=n;i++){
        int a,b,h;
        cin>>a>>b>>h;
        cubs.push_back(cub(a,b,h));
        cubs.push_back(cub(a,h,b));
        cubs.push_back(cub(b,h,a));
    }
    for(int i=0;i<cubs.size();i++) ans=max(ans,dp(i));
    return ans;
}
int main(){
    int n,tot=0;
    while(cin>>n&&n!=0) cout<<"Case "<<(++tot)<<": maximum height = "<<maintain(n)<<endl;
    return 0;
}
