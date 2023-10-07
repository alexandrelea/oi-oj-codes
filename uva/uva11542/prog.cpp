#include <iostream>
#include <cstring>
using namespace std;
bool vis[510];
int prime[510];
void sieve(int n){
    //eratosthenes
    vis[0]=vis[1]=true;
    for(int i=2;i*i<=n;i++) if(!vis[i]){
        for(int j=2;j*i<=n;j++) vis[i*j]=true;
    }
}
int gen_primes(int n){
    sieve(n);
    int c=0;
    for(int i=2;i<=n;i++) if(!vis[i])
        prime[c++]=i;
    return c;
}
typedef int Matrix[510][510];
int gauss(Matrix A,int m,int n){
    int i=0,j=0,k,r,u;
    while(i<m&&j<n){
        r=i;
        for(k=i;k<m;k++) if(A[k][j]){
            r=k;
            break;
        }
        if(A[r][j]){
            if(r!=i) for(k=0;k<=n;k++) swap(A[r][k],A[i][k]);
            for(u=i+1;u<m;u++) if(A[u][j])
                for(k=i;k<=n;k++) A[u][k]^=A[i][k];
            i++;
        }
        j++;
    }
    return i;
}
Matrix A;
int main(){
    int T,m=gen_primes(500);
    cin>>T;
    while(T--){
        int n,maxp=0;
        long long x;
        cin>>n;
        memset(A,0,sizeof(A));
        for(int i=0;i<n;i++){
            cin>>x;
            for(int j=0;j<m;j++) while(x%prime[j]==0){
                maxp=max(maxp,j);
                x/=prime[j];
                A[j][i]^=1;
            }
        }
        int r=gauss(A,maxp+1,n);
        cout<<(1ll<<(n-r))-1ll<<endl;
    }
    return 0;
}