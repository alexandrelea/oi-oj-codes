/**
 * @attention set.lower_bound(x) find the first element >= x.
 * @attention set.upper_bound(x) find the first element > x.
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int SIZE=6e5+10;
int n,m,w,a[SIZE]={},las[SIZE];
int maxa[SIZE]={}; // find the maxima value of interval [l,r].
int cnt=0; 
set<int> lut[SIZE];
void build(int cur,int lf,int rt){
    if(lf<rt){
        int mid=lf+(rt-lf)/2;
        build(cur*2,lf,mid);
        build(cur*2+1,mid+1,rt);
        maxa[cur]=max(maxa[cur*2],maxa[cur*2+1]);
        return;
    }
}
void modify(int cur,int lf,int rt,int mos,int mov){
    if(lf==rt) maxa[cur]=mov;
    else{
        int mid=lf+(rt-lf)/2;
        if(mos<=mid) modify(cur*2,lf,mid,mos,mov);
        else modify(cur*2+1,mid+1,rt,mos,mov);
        maxa[cur]=max(maxa[cur*2],maxa[cur*2+1]);
    }
}
int query(int cur,int lf,int rt,int qul,int qur){
    if(qul<=lf&&rt<=qur) return maxa[cur];
    int qry=0,mid=lf+(rt-lf)/2;
    if(qul<=mid) qry=max(qry,query(cur*2,lf,mid,qul,qur));
    if(mid<qur) qry=max(qry,query(cur*2+1,mid+1,rt,qul,qur));
    return qry;
}
int pre(int x){
    set<int>::iterator it1=lut[a[x]].lower_bound(x),it2=lut[w-a[x]].lower_bound(x);
    if(it2==lut[w-a[x]].begin()) return 0; 
    else if(it1==lut[a[x]].begin()) return *--it2; //find the x that at a[x].
    else if(*--it1>*--it2) return 0;
    else return *it2;
}
signed main(){
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=n;i++){
        modify(1,1,n,i,pre(i));
        lut[a[i]].insert(i);
    }
    while(m--){
        int o,x,y;
        cin>>o>>x>>y;
        if(o==1){
            vector<int> res;
            set<int>::iterator it=lut[a[x]].upper_bound(x);
            if(it!=lut[a[x]].end()) res.push_back(*it);
            it=lut[w-a[x]].upper_bound(x);
            if(it!=lut[w-a[x]].end()) res.push_back(*it);
            lut[a[x]].erase(x);
            lut[a[x]=y].insert(x);
            res.push_back(x);
            it=lut[a[x]].upper_bound(x);
            if(it!=lut[a[x]].end()) res.push_back(*it);
            it=lut[w-a[x]].upper_bound(x);
            if(it!=lut[w-a[x]].end()) res.push_back(*it);
            for(auto it:res) modify(1,1,n,it,pre(it));
        }else{
            x^=cnt,y^=cnt;
            if(query(1,1,n,x,y)>=x) cout<<"Yes"<<endl,cnt++;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}