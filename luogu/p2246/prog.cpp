#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[101];
const int mod = 1e9 + 7;
signed main()
{
    dp[0] = 1;
    char i;
    while (cin >> i)
    {
        if (!isalpha(i))
            continue;
        if (i <= 'Z')
            i += 32;
        if (i == 'h')
            dp[1]++;
        else if (i == 'e')
            (dp[2] += dp[1]) %= mod;
        else if (i == 'l')
        {
            (dp[9] += dp[8]) %= mod;
            (dp[4] += dp[3]) %= mod;
            (dp[3] += dp[2]) %= mod;
        }
        else if (i == 'o')
        {
            (dp[5] += dp[4]) %= mod;
            (dp[7] += dp[6]) %= mod;
        }
        else if (i == 'w')
            (dp[6] += dp[5]) %= mod;
        else if (i == 'r')
            (dp[8] += dp[7]) %= mod;
        else if (i == 'd')
            (dp[10] += dp[9]) %= mod;
    }
    cout << dp[10] << '\n';
    return 0;
}
