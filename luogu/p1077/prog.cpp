// FOR TEST!!!
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, m, a[105], dp[105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int k = 1; k <= a[i] && j - k >= 0; k++)
                dp[j] = (dp[j - k] + dp[j]) % mod;
    cout << dp[m] << endl;
    return 0;
}
