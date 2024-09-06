// UVa 10868 - Bungee Jumping
// Code by Alexandre Lea
#include <bits/stdc++.h>
using namespace std;
const double g=9.81;
double k,l,s,w;
void solve(){
	double t=0,h=s,dt=1e-2,a=0,v=0;
	while(true){
		t+=dt;
		a=k/w*(fabs(s-h)<l?0:fabs(s-h)-l)-g;
		v+=dt*a;
		h+=v*dt;
		if(h<dt*dt*dt){
			if(fabs(v)>10) cout<<"Killed by the impact."<<endl;
			else cout<<"James Bond survives."<<endl;
			return;
		}else if(fabs(v)<dt*dt){
			cout<<"Stuck in the air."<<endl;
			return;
		}
	}
}
int main(){
	while(cin>>k>>l>>s>>w&&(k!=0||l!=0||s!=0||w!=0)) solve();
	return 0;
}