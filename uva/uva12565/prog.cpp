#include <iostream>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#define fs(X) fixed<<setprecision(X)
using namespace std;
const double EPS=1e-40,ROX=12500;
int dcmp(double x){
    if(fabs(x)<EPS) return 0;
    else return x<0?-1:1;
}
struct point{
    double x,y;
    point(double cx=0,double cy=0):x(cx),y(cy){}
    point operator+(point b){
        return point(x+b.x,y+b.y);
    }
    point operator-(point b){
        return point(x-b.x,y-b.y);
    }
    point operator*(double cof){
        return point(x*cof,y*cof);
    }
    point operator/(double b){
        double xx=x/b,yy=y/b;
        if(dcmp(x)==0||dcmp(b)==0) xx=0;
        if(dcmp(y)==0||dcmp(b)==0) yy=0;
        return point(xx,yy);
    }
};
typedef point vecto;
double cross(vecto a,vecto b){
    return a.x*b.y-a.y*b.x;
}
struct segment{
    point p1,p2;
    segment(point p1,point p2):p1(p1),p2(p2){}
};
bool isintersected(point a1,point a2,point b1,point b2){
    double c1=cross(a2-a1,b1-a1),c2=cross(a2-a1,b2-a1),c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
point getintersection(point p,point v,point q,point w){
    point u=p-q;
    double t=cross(w,u)/cross(v,w);
    return p+v*t;
}
struct nurbs{
    int n,k,m;
    point P[25];
    double w[25],t[25];
    double N(int i,int k,double u){
        if(k==0) return (t[i]<=u&&u<t[i+1]?1.0:0.0);
        double co0,co1;
        if(dcmp(t[i+k]-t[i])==0||dcmp(u-t[i])==0) co0=0;
        else co0=(u-t[i])/(t[i+k]-t[i]);
        if(dcmp(t[i+k+1]-u)==0||dcmp(t[i+k+1]-t[i+1])==0) co1=0;
        else co1=(t[i+k+1]-u)/(t[i+k+1]-t[i+1]);
        return co0*N(i,k-1,u)+co1*N(i+1,k-1,u);
    }
    point C(double u){
        point num=point(0,0);
        double dem=0;
        for(int i=1;i<=n;i++){
            double coef=w[i]*N(i,k,u);
            num=num+P[i]*coef;
            dem+=coef;
        }
        return num/dem;
    }
    void clear(){
        n=k=m=0;
        for(int i=0;i<25;i++) P[i].x=P[i].y=w[i]=t[i]=0;
    }
}curv[3];
vector<pair<segment,int>> aprlin;
const int BOTTOM=0,TOP=1,INTERSECT=-1;
struct endpoint{
    point p;
    int seg,ges,st;
    endpoint(point p=point(0,0),int seg=0,int ges=0,int st=0):p(p),seg(seg),ges(ges),st(st){}
};
struct node{
    endpoint ep;
    node *next;
    node(endpoint ep=endpoint(),node *next=nullptr):ep(ep),next(next){}
}*head;
void approx(int num){
    double st=1/ROX;
    vector<point> aprdot;
    for(double i=0;i*st<1;i++) aprdot.push_back(curv[num].C(st*i));
    for(int i=1;i<aprdot.size();i++) aprlin.push_back(make_pair(segment(aprdot[i-1],aprdot[i]),num));
}
void intersections(vector<point> &ans){
    vector<endpoint> edps;
    int n=aprlin.size();
    for(int i=0;i<n;i++){
        if(aprlin[i].first.p1.y>aprlin[i].first.p2.y){
            edps.push_back(endpoint(aprlin[i].first.p1,i,0,TOP));
            edps.push_back(endpoint(aprlin[i].first.p2,i,0,BOTTOM));
        }else{
            edps.push_back(endpoint(aprlin[i].first.p1,i,0,BOTTOM));
            edps.push_back(endpoint(aprlin[i].first.p2,i,0,TOP));
        }
    }
    sort(edps.begin(),edps.end(),[](endpoint a,endpoint b)->bool {return a.p.y!=b.p.y?a.p.y>b.p.y:a.p.x<b.p.x;});
    head=new node;
    node *cur=head,*co=head;
    for(int i=0;i<2*n;i++){
        cur->ep=edps[i];
        if(cur->next==nullptr) cur->next=new node;
        co=cur,cur=cur->next;
    }
    delete cur,co->next=nullptr;
    cur=head;
    struct cmp{
        bool operator()(int a,int b){
            point at,bt;
            if(aprlin[a].first.p1.y<aprlin[a].first.p2.y) at=aprlin[a].first.p2;
            else at=aprlin[a].first.p1;
            if(aprlin[b].first.p1.y<aprlin[b].first.p2.y) bt=aprlin[b].first.p2;
            else bt=aprlin[b].first.p1;
            return at.x<bt.x;
        }
    };
    set<int,cmp> bst;
    // set<int> bst;
    while(cur!=nullptr){
        if(cur->ep.st==TOP){
            bst.insert(cur->ep.seg);
            auto it=bst.lower_bound(cur->ep.seg),lt=it,rt=it;
            rt++;
            if(rt!=bst.end()){
                if(isintersected(aprlin[*it].first.p1,aprlin[*it].first.p2,aprlin[*rt].first.p1,aprlin[*rt].first.p2)){
                    point pi=getintersection(aprlin[*it].first.p1,aprlin[*it].first.p2-aprlin[*it].first.p1,aprlin[*rt].first.p1,aprlin[*rt].first.p2-aprlin[*rt].first.p1);
                    node *nx=cur->next,*add=new node;
                    add->ep=endpoint(pi,*it,*rt,INTERSECT);
                    add->next=nx,cur->next=add;
                }
            }
            if(lt!=bst.begin()){
                lt--;
                if(isintersected(aprlin[*it].first.p1,aprlin[*it].first.p2,aprlin[*lt].first.p1,aprlin[*lt].first.p2)){
                    point pi=getintersection(aprlin[*it].first.p1,aprlin[*it].first.p2-aprlin[*it].first.p1,aprlin[*lt].first.p1,aprlin[*lt].first.p2-aprlin[*lt].first.p1);
                    node *nx=cur->next,*add=new node;
                    add->ep=endpoint(pi,*lt,*it,INTERSECT);
                    add->next=nx,cur->next=add;
                }
            }
        }else if(cur->ep.st==BOTTOM){
            auto it=bst.lower_bound(cur->ep.seg),lt=it,rt=it;
            ++rt;
            if(lt!=bst.begin()&&rt!=bst.end()){
                lt--;
                if(isintersected(aprlin[*rt].first.p1,aprlin[*rt].first.p2,aprlin[*lt].first.p1,aprlin[*lt].first.p2)){
                    point pi=getintersection(aprlin[*rt].first.p1,aprlin[*rt].first.p2-aprlin[*rt].first.p1,aprlin[*lt].first.p1,aprlin[*lt].first.p2-aprlin[*lt].first.p1);
                    node *nx=cur->next,*add=new node;
                    add->ep=endpoint(pi,*lt,*rt,INTERSECT);
                    add->next=nx,cur->next=add;
                }
            }
            bst.erase(cur->ep.seg);
        }else if(cur->ep.st==INTERSECT){
            if(aprlin[cur->ep.seg].second+aprlin[cur->ep.ges].second==3) ans.push_back(cur->ep.p);
            auto it=bst.lower_bound(cur->ep.seg),jt=bst.lower_bound(cur->ep.ges);
            auto lt=it,rt=jt;
            if(rt!=bst.end()){
                if(isintersected(aprlin[*jt].first.p1,aprlin[*jt].first.p2,aprlin[*rt].first.p1,aprlin[*rt].first.p2)){
                    point pi=getintersection(aprlin[*jt].first.p1,aprlin[*jt].first.p2-aprlin[*jt].first.p1,aprlin[*rt].first.p1,aprlin[*rt].first.p2-aprlin[*rt].first.p1);
                    node *nx=cur->next,*add=new node;
                    add->ep=endpoint(pi,*jt,*rt,INTERSECT);
                    add->next=nx,cur->next=add;
                }
            }
            if(lt!=bst.begin()){
                lt--;
                if(isintersected(aprlin[*lt].first.p1,aprlin[*lt].first.p2,aprlin[*it].first.p1,aprlin[*it].first.p2)){
                    point pi=getintersection(aprlin[*lt].first.p1,aprlin[*lt].first.p2-aprlin[*lt].first.p1,aprlin[*it].first.p1,aprlin[*it].first.p2-aprlin[*it].first.p1);
                    node *nx=cur->next,*add=new node;
                    add->ep=endpoint(pi,*lt,*it,INTERSECT);
                    add->next=nx,cur->next=add;
                }
            }
        }
        cur=cur->next;
    }
    cur=head;
    do{
        node *co=cur->next;
        delete cur;
        cur=co;
    }while(cur!=nullptr);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int tid=1;tid<=T;tid++){
        if(tid>1) cout<<endl;
        aprlin.clear();
        for(int i=1;i<=2;i++) curv[i].clear();
        for(int i=1;i<=2;i++){
            cin>>curv[i].n>>curv[i].m,curv[i].k=curv[i].m-curv[i].n-1;
            for(int j=1;j<=curv[i].n;j++) cin>>curv[i].P[j].x>>curv[i].P[j].y>>curv[i].w[j];
            for(int j=1;j<=curv[i].m;j++) cin>>curv[i].t[j];
            approx(i);
        }
        vector<point> ans;
        intersections(ans);
        cout<<"Case "<<tid<<": ";
        if(ans.empty()){
            cout<<0<<endl;
            continue;
        }
        sort(ans.begin(),ans.end(),[](point a,point b)->bool {return a.x!=b.x?a.x<b.x:a.y<b.y;});
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<"("<<fs(3)<<it.x<<", "<<fs(3)<<it.y<<")"<<endl;
        }

    }
    return 0;
}
