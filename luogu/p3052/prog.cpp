#include <iostream>
#include <cmath>
using namespace std;
const long double endtemp=1e-60,delt=0.9999;
int n,w,lastans,best,nowans,x,y,max,maxt;
int sum,pos,recsum,recpos,a[30];
bool flag,vis[30];
long double temp=1e40;
int calc(){
    int cnt,ans;
    cnt=ans=0;
    for(int i=1;i<=n;i++){
        if(cnt+a[i]>w) ans++,cnt=0;
        cnt+=a[i];
    }
    if(cnt>0) ans++;
    return ans;
}
bool accept(long double temp,long double delta){
    long double raand;
    if(delta>=0) return true;
    raand=((long double)(rand()%2348284))/2348284.0;
    if(raand<exp(delta/temp)) return true;
    else return false;
}
int main(){
    srand(time(nullptr));
    cin>>n>>w;
    for(int i=1;i<=n;i++) cin>>a[i];
    best=lastans=calc();
    for(int i=1;i<=5;i++){
        while(temp>endtemp){
            y=x=rand()%n+1;
            while(y==x) y=rand()%n+1;
            swap(x,y);
            nowans=calc();
            if(accept(temp,lastans-nowans)) lastans=nowans;
            else swap(x,y);
            if(nowans<best) best=nowans;
            temp*=delt;
        }
        temp=1e40;
    }
    cout<<best<<endl;
    return 0;
}