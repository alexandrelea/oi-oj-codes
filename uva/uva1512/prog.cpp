#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
char ex[25][85];
int min(int x,int y){
    return x<y?x:y;
}
int max(int x,int y){
    return x>y?x:y;
}
int pow(int a,int b,int p=2011){
    int ans=1;
    for(;b!=0;b/=2,a=a*a%p) if(b%2==1) ans=ans*a%p;
    return ans;
}
int inv(int x){
    return pow(x,2009);
}
int calc(int x0,int y0,int x1,int y1){
    int bal=x0;
    for(int i=x0;i<=x1;i++) if(ex[i][y0]!='.'){
        bal=i;
        break;
    }
    printf("# %d %d %d %d\n",x0,y0,x1,y1);
    int sum=0,now=1,sym=1;
    for(int i=y0;i<=y1;i++){
        if(ex[bal][i]>='0'&&ex[bal][i]<='9'){
            int b=ex[bal][i]-'0',e=1;
            if(ex[bal-1][i+1]>='0'&&ex[bal-1][i+1]<='9') e=ex[bal-1][i+1]-'0';
            now=(now*pow(b,e))%2011;
        }else if(ex[bal][i]=='-'&&ex[bal][i+1]=='.'){
            if(i-2<y0||ex[bal][i-2]=='*'||ex[bal][i-2]=='-'||ex[bal][i-2]=='+') sym=sym*(-1);
            else sum+=(sym*now),now=1,sym=-1;
        }else if(ex[bal][i]=='*');
        else if(ex[bal][i]=='+') sum=((sum+now*sym)%2011+2011)%2011,now=1,sym=1;
        else if(ex[bal][i]=='('){
            int nxb=i+1,ore=1;
            for(int j=i+1;j<=y1;j++){
                if(ex[bal][j]==')') ore--;
                else if(ex[bal][j]=='(') ore++;
                nxb=j;
                if(ore==0) break;
            }
            int b=calc(x0,i+2,x1,nxb-2),e=1;
            if(ex[bal-1][nxb+1]>='0'&&ex[bal-1][nxb+1]<='9') e=ex[bal-1][nxb+1]-'0';
            now=(sym*now*pow(b,e)%2011+2011)%2011;
            i=nxb,sym=1;
        }else if(ex[bal][i]=='-'&&ex[bal][i+1]=='-'){
            int frm=i,fxe=i+1;
            for(int j=i+1;j<=y1;j++){
                if(ex[bal][j]=='-') fxe=j;
                else break;
            }
            int fron=fxe,end=frm,num,dem;
            for(int i=x0;i<bal;i++){
                for(int j=frm;j<=fxe;j++) if(ex[i][j]!='.'){
                    fron=min(fron,j);
                    break;
                }
                for(int j=fxe;j>=frm;j--) if(ex[i][j]!='.'){
                    end=max(end,j);
                    break;
                }
            }
            num=calc(x0,fron,bal-1,end);
            fron=fxe,end=frm;
            for(int i=bal+1;i<=x1;i++){
                for(int j=frm;j<=fxe;j++) if(ex[i][j]!='.'){
                    fron=min(fron,j);
                    break;
                }
                for(int j=fxe;j>=frm;j--) if(ex[i][j]!='.'){
                    end=max(end,j);
                    break;
                }
            }
            dem=calc(bal+1,fron,x1,end);
            i=fxe;
            now=(now*num%2011+2011)%2011;
            now=(now*inv(dem)%2011+2011)%2011;
            now*=sym,sym=1;
        }
    }
    sum=((sum+now*sym)%2011+2011)%2011,now=1;
    for(int i=x0;i<=x1;i++){
        for(int j=y0;j<=y1;j++) printf("%c",ex[i][j]);
        if(i==bal) printf("=%d",sum);
        printf("\n");
    }
    printf("\n");
    return sum;
}
void maintain(){
    memset(ex,0,sizeof(ex)); 
    for(int i=1;i<=n;i++) scanf("%s",ex[i]+1),m=strlen(ex[i]+1);
    printf("%d\n",calc(1,1,n,m));
}
int main(){
    while(scanf("%d",&n)==1&&n!=0) maintain();
    return 0;
}