#include <bits/stdc++.h>
using namespace std;
int n, p[205], cnt;
bool a[205][205];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int t;
        while (1)
        {
            cin >> t;
            if (!t)
                break;
            a[i][t] = 1;
        }
    }
    for (int k = 1; k < +n; k++)
        for (int i = 1; i < +n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j])
                p[j] = p[i];
    for (int i = 1; i <= n; i++)
        if (p[i] == i)
            cnt++;
    cout << cnt;

    return 0;
}
