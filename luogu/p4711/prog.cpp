#include <bits/stdc++.h>
using namespace std;
map<string,int> ar={{"H",2},{"C",24},{"N",28},{"O",32},{"F",38},{"Na",46},{"Mg",48},{"Al",54},{"Si",56},{"P",62},{"S",64},{"Cl",71},{"K",78},{"Ca",80},{"Mn",110},{"Fe",112},{"Cu",128},{"Zn",130},{"Ag",216},{"I",254},{"Ba",274},{"Hf",357},{"Pt",390},{"Au",394},{"Hg",402}};

int main(){
    string mo;
    int ans=0,hyd;
    cin>>mo;
    hyd=mo.length();
    if(mo.find('~')!=string::npos){
        hyd=mo.find('~');
        if(mo[hyd+1]=='H') ans+=36;
        else{
            int nu=0;
            for(int i=hyd+1;mo[i]!='H';++i) nu=nu*10+mo[i]-'0';
            ans+=nu*36;
        }
    }
    for(int i=0;i<hyd;++i){
        int pm=0;
        if('A'<=mo[i]&&mo[i]<='Z'){
            string ele="  ";
            if('A'<=mo[i]&&mo[i]<='Z') ele[0]=mo[i];
            if(i+1<hyd&&'a'<=mo[i+1]&&mo[i+1]<='z') ele[1]=mo[i+1],++i;
            else ele=" ",ele[0]=mo[i];
            pm+=ar[ele];
        }else if(mo[i]=='('){
            for(int j=i+1;mo[j]!=')';++j){
                int ppm=0;
                if('A'<=mo[j]&&mo[j]<='Z'){
                    string ele="  ";
                    if('A'<=mo[j]&&mo[j]<='Z') ele[0]=mo[j];
                    if(j+1<hyd&&'a'<=mo[j+1]&&mo[j+1]<='z') ele[1]=mo[j+1],++j;
                    else ele=" ",ele[0]=mo[j];
                    ppm+=ar[ele];
                }
                if(mo[j+1]=='_'){
                    int nu=0;
                    for(int k=j+3;mo[k]!='}';++k) nu=nu*10+mo[k]-'0',j=k;
                    ++j;
                    pm+=ppm*nu;
                }else pm+=ppm;
                i=j;
            }
            ++i;
        }
        if(mo[i+1]=='_'){
            int nu=0;
            for(int j=i+3;mo[j]!='}';++j) nu=nu*10+mo[j]-'0',i=j;
            ++i;
            ans+=pm*nu;
        }else ans+=pm;
    }
    cout<<(double)ans/2<<endl;
    return 0;
}