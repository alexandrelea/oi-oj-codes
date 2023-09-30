#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
const int SIZE=1e5+10;
int n,k,a[SIZE];
vector<int> v;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    n=
    cout<<a[(k-1)/n+1]<<" "<<a[(k-1)%n+1]<<endl;
    return 0;
}
/*

1 1 2

*/