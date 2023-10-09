#include <iostream>
#include <string>
using namespace std;
const int INF=715827882;
int main(){
    int am=INF,bm=INF,cm=INF,abm=INF,acm=INF,bcm=INF,abcm=INF,ans,n,c;
    string s;
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c>>s;
		if(s=="A") am=min(am,c);
		else if(s=="B") bm=min(bm,c);
		else if(s=="C") cm=min(cm,c);
		else if(s=="AB") abm=min(abm,c);
		else if(s=="BA") abm=min(abm,c);
		else if(s=="AC") acm=min(acm,c);
		else if(s=="CA") acm=min(acm,c);
		else if(s=="BC") bcm=min(bcm,c);
		else if(s=="CB") bcm=min(bcm,c);
		else abcm=min(abcm,c);
	}
	ans=min(abcm,min(am+bm+cm,min(abm+cm,min(acm+bm,min(bcm+am,min(abm+bcm,min(abm+acm,acm+bcm)))))));
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}