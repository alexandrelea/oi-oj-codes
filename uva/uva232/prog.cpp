#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int cnt=0;
    while(!cin.eof()){
        int r,c;
        char prob[12][12]={};
        int number[12][12]={};
        bool hor[12][12]={},ver[12][12]={};
        cin>>r;
        if(r==0) return 0;
        cin>>c;
        for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) cin>>prob[i][j];
        if(cnt!=0) cout<<endl;
        cout<<"puzzle #"<<++cnt<<":"<<endl;
        int num=1;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(prob[i][j]!='*'&&(((i-1>=1&&prob[i-1][j]=='*')||i==1)||((j-1>=1&&prob[i][j-1]=='*')||j==1))){
                    number[i][j]=num;
                    num++;
                }
            }
        }
        cout<<"Across"<<endl;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(hor[i][j]==false && prob[i][j]!='*'){
                    cout<<setw(3)<<number[i][j]<<".";
                    for(int k=j;prob[i][k]!='*'&&k<=c;k++){
                        cout<<prob[i][k];
                        hor[i][k]=true;
                    }
                    cout<<endl;
                }
            }
        }
        cout<<"Down"<<endl;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(ver[i][j]==false&&prob[i][j]!='*'){
                    cout<<setw(3)<<number[i][j]<<".";
                    for(int k=i;prob[k][j]!='*'&&k<=r;k++){
                        cout<<prob[k][j];
                        ver[k][j]=true;
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}